#include <stdio.h>
#include <unistd.h>

// basic, you know lah

int main() {
    char buffer[40];
    read(0,buffer,40);
    puts(buffer);
    return 0;
}