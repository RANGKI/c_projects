#include <stdio.h>
#include <stdlib.h>
#include <sys/sendfile.h>
#include <fcntl.h>

int main() {
    char *name = malloc(8);
    printf("whats your name : ");
    scanf("%7s",name);
    printf("Hello %s !\n",name);
    free(name);
    int *authorize = malloc(8);
    *authorize = 0;
    printf("oh yeah whats your name again : ");
    scanf("%7s",name);
    puts("okay byee");
    if (authorize != 0) {
        int prize = open("flag.txt",O_RDONLY);
        if (prize == 0) {
            puts("add the flag.txt to the current directory please");
        }
        sendfile(0,prize,NULL,255);
    }
    return 0;
}