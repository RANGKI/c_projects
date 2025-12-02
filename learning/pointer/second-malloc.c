#include <stdio.h>
#include <stdlib.h>

void test_lockin(char *whyImLockin);

int main() {
    char why_im_lockin[256];
    puts("lock tf in bro : ");
    char *im_malloc = malloc(sizeof(why_im_lockin));
    fgets(im_malloc,sizeof(why_im_lockin),stdin);
    printf("it is because im %s\n",im_malloc);
    test_lockin(im_malloc);
    printf("My second reason is because %s\n",im_malloc);
    free(im_malloc);
    return 0;
}

void test_lockin(char *whyImLockin) {
    puts("but your second reason please : ");
    scanf("%255s",whyImLockin);
    return;
}