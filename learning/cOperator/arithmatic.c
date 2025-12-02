#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    int add = a + b;
    printf("the adding of a + b is %d\n",add);
    int sub = b - a;
    printf("the subtraction of b - a is : %d\n",sub);
    int mul = a * b;
    printf("the multiplication of a x b is : %d\n",mul);
    int div = b / a;
    printf("the division of b / a is : %d\n",div);
    int modulus = b % a;
    printf("the modulo from b and a is : %d\n",modulus);
    int increase = ++a;
    printf("the increase of a is : %d\n",increase);
    int decrease = --a;
    printf("the decrease of a is : %d\n",decrease);
    return 0;
}