#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void parse(const char* line)
{
    char method[16];
    char path[1024];
    char query[1024];

    method[0] = 0;
    path[0]   = 0;
    query[0]  = 0;

    // method
    sscanf(line, "%15s", method);

    // find first space (after method)
    const char *p = strchr(line, ' ');
    if (!p) return; // malformed

    p++; // skip space

    // find space after path/query
    const char *end = strchr(p, ' ');
    if (!end) return;

    // check if query exists
    const char *qmark = strchr(p, '?');

    if (qmark && qmark < end) {
        // copy path
        size_t path_len = qmark - p;
        strncpy(path, p, path_len);
        path[path_len] = '\0';

        // copy query
        size_t query_len = end - qmark - 1;
        strncpy(query, qmark + 1, query_len);
        query[query_len] = '\0';
    } else {
        // only path
        size_t path_len = end - p;
        strncpy(path, p, path_len);
        path[path_len] = '\0';
    }

    printf("METHOD: %s\n", method);
    printf("PATH  : %s\n", path);
    printf("QUERY : %s\n", query[0] ? query : "(none)");
}


int main() {
    char request[2048];
    struct sockaddr_in bind_data;
    struct sockaddr_in client_data;
    bind_data.sin_family = AF_INET;
    bind_data.sin_port = htons(0);
    bind_data.sin_addr.s_addr = htonl(INADDR_ANY);
    int socket_fd = socket(AF_INET,SOCK_STREAM,0);
    socklen_t addr_len = sizeof(bind_data);
    socklen_t client_len = sizeof(client_data);
    int is_bind = bind(socket_fd,(struct sockaddr*) &bind_data,sizeof(bind_data));
    getsockname(socket_fd,(struct sockaddr*) &bind_data,&addr_len);
    int port = ntohs(bind_data.sin_port);
    printf("the server is running in port {%d}\n",port);
    int is_listen = listen(socket_fd,128);
    while(1) {
        int client_fd = accept(socket_fd,(struct sockaddr*) &client_data,&client_len);
        if (client_fd < 0) {
            puts("wtf is the error man");
            exit(1);
        }
        getsockname(socket_fd,(struct sockaddr*) &client_data,&client_len);
        int addr = ntohl(client_data.sin_addr.s_addr);
        printf("a client connected from {%d} addr\n",addr);
        read(client_fd,request,2048);
        parse(request);
        int fd = open("index.html", O_RDONLY);
        if (fd < 0) {
            perror("open");
            exit(1);
        }

        char body[4096];
        int body_len = read(fd, body, sizeof(body));

        char header[256];
        int header_len = snprintf(header, sizeof(header),
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n"
            "Content-Length: %d\r\n"
            "\r\n",
            body_len
        );

        // send header
        write(client_fd, header, header_len);

        // send file body
        write(client_fd, body, body_len);

    }
    return 0;
}