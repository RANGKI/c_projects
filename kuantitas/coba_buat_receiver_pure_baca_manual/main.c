#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */

int main(int argc, char **argv) {
    // man 7 ip
    struct sockaddr_in my_sock_addr;
    struct in_addr my_in_addr;

    int my_socket = socket(AF_INET, SOCK_STREAM, 0);
    // this operation is called “assigning a name to a socket”.
    // man 2 bind
    if(my_socket) {
        puts("Opening TCP Socket");
    }
    my_sock_addr.sin_family = AF_INET;
    my_sock_addr.sin_port = htons(9999);
    my_in_addr.s_addr = INADDR_ANY;
    my_sock_addr.sin_addr = my_in_addr;
    int is_binding_success = bind(my_socket, (const struct sockaddr *)&my_sock_addr, sizeof(my_sock_addr));
    if (is_binding_success == 0) {
        printf("Listening on port %u\n",ntohs(my_sock_addr.sin_port));
    }

    return 0;
}