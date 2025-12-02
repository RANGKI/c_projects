#include <stdio.h>
#include <stdlib.h>

void test_lockin(int *lock_in);

int main() {
    int lockIn;
    lockIn = 20;
    int *im_malloc = malloc(sizeof(lockIn));
    *im_malloc = 20;
    puts("========");
    test_lockin(im_malloc);
    printf("Current lockin : %d\n",*im_malloc);
    free(im_malloc);
    return 0;
}

void test_lockin(int *lock_in) {
    printf("Current lockin : %d\n",*lock_in);
    *lock_in = 40;
    printf("Current lockin : %d\n",*lock_in);
    *lock_in = 60;
    return;
}
