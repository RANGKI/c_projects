#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *tes = "S1MPL3_X0R";

int main(int argc, char **argv) {
    char flag[33];
    size_t flag_len;
    puts("Welcome to simple xor");
    printf("Enter the flag: ");
    scanf("%33s",flag);
    flag_len = strlen(flag);
    if (flag_len != 32) {
        puts("WRONG LENGTH !");
        exit(1);
    }
    for (int i; i < flag_len;i++) {
        flag[i] = flag[i] ^ tes[i % strlen(tes)];
    }
    printf("FLAG: %33s\n",flag);
    return 0;
}