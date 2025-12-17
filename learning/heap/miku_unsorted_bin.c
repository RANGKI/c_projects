#include <stdio.h>
#include <stdlib.h>

int main() {
    void *mallocss[7];
    mallocss[0] = malloc(0x420);
    mallocss[1] = malloc(0x500);
    mallocss[2] = malloc(0x600);
    free(mallocss[0]);
    free(mallocss[1]);
    free(mallocss[2]);
    return 0;
}