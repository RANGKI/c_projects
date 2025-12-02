#include <stdio.h>

int main() {
    int a = 100;
    int b = 88;
    a -= b;
    if (a < 50) {
        a += 200;
        if (a > 400) {
            return 0;
        } else {
            if ( a > 200) {
                a -= 100;
                printf("the final value is : %d\n",a);
            }
        }
    }
    return 0;
}