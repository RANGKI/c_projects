#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define SIZE 50
#define PATH_SIZE 2000
struct dirent **vault[SIZE];

void scaning(char *dirp, int i);

int main(int argc, char **argv) {
    char *dir_target = malloc(sizeof(char) * 2000);
    if (argc < 2) {
        printf("Usage %s <dir>\n",argv[0]);
        exit(0);
    }
    snprintf(dir_target,PATH_SIZE,"%s",argv[1]);
    scaning(dir_target,0);
    free(dir_target);
    return 0;
}

void scaning(char *dirp,int i) {
    int length = scandir(dirp,&vault[i],NULL,NULL);
    struct dirent *scan_result;
    char *dir_target = malloc(sizeof(char) * 2000);
    for (int o = 0; o < length; o++) {
        scan_result = vault[i][o];
        if (scan_result->d_type == DT_DIR) {
            if (strcmp(scan_result->d_name,".") != 0  && strcmp(scan_result->d_name,"..") != 0) {
                snprintf(dir_target,PATH_SIZE,"%s/%s",dirp,scan_result->d_name);
                scaning(dir_target,i + 1);
            }
        }
        printf("%s/%s\n",dirp,scan_result->d_name);
        free(scan_result);
    }
    free(vault[i]);
    free(dir_target);
}

// cons: still not implementing dynamic size, (AKA still using static value)