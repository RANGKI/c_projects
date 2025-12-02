#include <stdio.h>

// scanf overwrite last byte yang dia timpa menjadi 0x00, usahakan jangan gunakan scanf saat mau overwrite sesuatu

int main() {
    char tes[40];
    scanf("%40s",tes);
    puts(tes);
    scanf("%40s",tes);
    puts(tes);
    return 0;
}