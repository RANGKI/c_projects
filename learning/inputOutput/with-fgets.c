#include <stdio.h>

// fungsi fgest menambahkan newline dan null byte 0xa dan 0x0 pada length terakhir buffer

int main() {
    char buffer[40];
    fgets(buffer,40,stdin); // stdin merupakan variable spesial yang menyimpan address libc untuk berhubungan dengan input output dan error, disini karena kita butuh input maka masukkan spesial variable stdin
    puts(buffer);
    fgets(buffer,40,stdin); // stdin merupakan variable spesial yang menyimpan address libc untuk berhubungan dengan input output dan error, disini karena kita butuh input maka masukkan spesial variable stdin
    puts(buffer);
    return 0;
}