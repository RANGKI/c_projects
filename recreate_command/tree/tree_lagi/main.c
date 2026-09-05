#define _GNU_SOURCE
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_LIST 50
#define PATH_SIZE 1000

struct dirent **namelist[SIZE_LIST];

int pohon(char *path, int index);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage %s <path> \n",argv[0]);
        exit(1);
    }
    char *first_path = argv[1];
    printf("Scanning %s\n",first_path);
    pohon(first_path,0);
}

int pohon(char *path, int index) {
    int counter = scandir(path,&namelist[index],0,0);
    for (int i = 0; i < counter; i++) {
        struct dirent *current_dirrent = namelist[index][i];
        if (current_dirrent->d_type == DT_DIR) {
            if (strncmp(current_dirrent->d_name,".",1) != 0 && strncmp(current_dirrent->d_name,"..",2) != 0) {
                char new_path[PATH_SIZE];
                snprintf(new_path,PATH_SIZE,"%s/%s",path,current_dirrent->d_name);
                pohon(new_path,index + 1);
            }
        }
        printf("%s/%s\n",path,current_dirrent->d_name);
        free(current_dirrent);
    }
    free(namelist[index]);
}