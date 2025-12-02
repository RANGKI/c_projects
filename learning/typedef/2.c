#include <stdio.h>

struct myBiography {
    int age;
    char name[40];
};

typedef struct myInformation {
    int age;
    char name[40];
} Rangki;

void read_rangki(Rangki rangkii);

int main() {
    struct myBiography alfin;
    alfin.age = 17;
    puts("masukkan nama anda : ");
    fgets(alfin.name,40,stdin);
    printf("Hello %s with %d age !\n",alfin.name,alfin.age);
    Rangki rangki;
    rangki.age = 17;
    puts("masukkan nama rangki : ");
    scanf("%40s",rangki.name);
    printf("Hello %s with %d age !\n",rangki.name,rangki.age);
    read_rangki(rangki);
    return 0;
}

void read_rangki(Rangki rangkii) {
    printf("Hello %s with %d age !\n",rangkii.name,rangkii.age);
}