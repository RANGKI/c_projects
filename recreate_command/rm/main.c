#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>

int main(int argc, char **argv) {
    char *filename = argv[1];
    if (argc < 2) {
        printf("%s program, need at least 1 argument. rm [OPTION] <file>\n",argv[0]);
        exit(1);
    }

    unlink(filename);

    printf("%s removed \n",filename);

    return 0;
}