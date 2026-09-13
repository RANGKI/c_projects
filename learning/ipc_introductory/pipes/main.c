#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *pwend = "PWEND";

int main(int argc, char **argv) {
    char buffer[6];
    pid_t child;
    int pipefd[2];

    memset(buffer,0,6);
    if (pipe(pipefd) < 0) {
        perror("Opening pipe stream");
        exit(1);
    }
    child = fork();
    if (child == -1) {
        perror("Performing fork");
        exit(1);
    } else {
        if (child == 0) {
            puts("Its the child process");
            printf("Look The pid return from the fork is %d\n",child);

            puts("The child is sending data pwned to the parent");
            write(pipefd[1],pwend,5);
        } else {
            puts("Its the parent process");
            printf("Look The pid return from the fork is %d\n",child);
            read(pipefd[0],buffer,5);
            printf("Read the message from my child : %s\n\n",buffer);
        }
    }
    return 0;
}