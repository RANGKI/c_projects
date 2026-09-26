#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <error.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define SOCKET_PATH "udp_socket\x00"

int main(int argc, char **argv) {
    putchar(argv[1][0]);
    int socket_fd;
    struct sockaddr_un local_socket;
    char buffer[1000];

    socket_fd = socket(AF_UNIX,SOCK_DGRAM,0);

    if (socket_fd == -1) {
        perror("Socket error : ");
        exit(1);
    }

    local_socket.sun_family = AF_UNIX;
    strncpy(local_socket.sun_path,SOCKET_PATH,12);

    memset(buffer,argv[1][0],1000);
    connect(socket_fd,(const struct sockaddr *) &local_socket,sizeof(struct sockaddr_un));
    write(socket_fd,buffer,1000);
    return 0;
}