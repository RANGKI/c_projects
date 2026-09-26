#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stdlib.h>
#include <error.h>
#include <unistd.h>


#define SOCKET_PATH "udp_socket\x00"

int main(int argc, char **argv) {
    int socket_fd;
    struct sockaddr_un local_sockaddr;
    char buffer[1000];

    socket_fd = socket(AF_UNIX,SOCK_DGRAM,0);

    if (socket_fd == -1) {
        perror("First time using perror gng : ");
        exit(1);
    }

    local_sockaddr.sun_family = AF_UNIX;
    strncpy(local_sockaddr.sun_path,SOCKET_PATH,12);

    bind(socket_fd,(const struct sockaddr *) &local_sockaddr,sizeof(struct sockaddr_un));
    
    for(;;) {
        read(socket_fd,buffer,sizeof(buffer));
        write(0,buffer,sizeof(buffer));
        if (buffer[0] == 'e') break;
    }

    close(socket_fd);
    // fix error 98
    unlink(SOCKET_PATH);
}