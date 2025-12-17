#include <stdio.h>
#include <stdlib.h>
#include <sys/sendfile.h>
#include <fcntl.h>

int main() {
    char *name = malloc(8);
    char *password = malloc(8);
    printf("Whats your name : ");
    scanf("%7s",name);
    printf("Whats your password : ");
    scanf("%7s",password);
    free(name);
    free(password);
    printf("%s\n",name);
    return 0;
}