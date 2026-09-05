#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    struct dirent **namelist;
    struct dirent *tempat;
    int i = 0;
    if (argc < 2) {
        printf("usage %s <dir>\n",argv[0]);
        exit(0);
    }
    scandir(argv[1],&namelist,NULL,NULL);
    tempat = namelist[i];
    while (tempat != NULL) {
        printf("%s\n",tempat->d_name);
        i += 1;
        tempat = namelist[i];
    }
    return 0;
}