#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>

int main() {
    char *current_dir_path;
    current_dir_path = get_current_dir_name();
    printf("%s\n",current_dir_path);
    return 0;
}