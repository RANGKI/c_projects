#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
    char *val1, *val2;

    val1 = malloc(12);
    val2 = malloc(30);

    strcpy(val1, "LoremIpsum1");
    strcpy(val2, "LoremIpsum2");

    free(val1);
    free(val2);
}
