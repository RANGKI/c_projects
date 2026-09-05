#include <stdio.h>
#include <string.h>

char nama_siswa[8][64];

void banner();
int get_index();
void tambahkan_siswa(int siswa_keberapa);
void tampilkan_siswa();
void hapus_siswa();
// void edit_siswa;

int jumlah_siswa = 0;

int main(int argc, char **argv) {
    int opsi;
    int index;
    banner();
    while(1) {
        printf("Jumlah siswa saat ini -> %d\n",jumlah_siswa);
        putchar(10);
        printf("Silahkan masukkan opsi: ");
        scanf("%d",&opsi);
        putchar(10);
        if (opsi == 1) {
            banner();
        } else if (opsi == 2) {
            index = get_index();
            if (index != 1337) {
                tambahkan_siswa(index);
            }
        } else if (opsi == 3) {
            index = get_index();
            if (index != 1337) {
                hapus_siswa(index);
            }
        } else if (opsi == 4) {
            tampilkan_siswa();
        } else if (opsi == 5) {
            return 0;
        } else if (opsi == 6) {
            puts("Byee friend");
            break;
        } else {
            puts("Opsi tidak valid !");
        }
    }
    return 0;
}

void banner() {
    puts("=============================");
    puts("Welcome to 8 Siswa");
    puts("=============================");
    puts("1. Banner");
    puts("2. Tambah siswa (MAX : 8)");
    puts("3. Hapus siswa");
    puts("4. Tampilkan siswa");
    puts("5. Hapus siswa");
    puts("6. exit");
}

int get_index() {
    int index;
    printf("Index keberapa : ");
    scanf("%d%*c",&index);
    if (index >= 0 && index < 8) {
        return index;
    } else {
        puts("Invalid index..");
        putchar(10);
        return 1337;
    }
}

void tambahkan_siswa(int index_siswa_keberapa) {
    int clearing;
    printf("Masukkan nama siswa (MAX LENGTH 64 !) : ");
    fgets(nama_siswa[index_siswa_keberapa],64,stdin);
    clearing = strcspn(nama_siswa[index_siswa_keberapa],"\n");
    nama_siswa[index_siswa_keberapa][clearing] = '\0';
    jumlah_siswa++;
}

void tampilkan_siswa() {
    puts("=============================");
    puts("the entirity of siswa");
    puts("=============================");
    for (int i = 0; i < 8; i++) {
        printf("%d. %s\n",i,nama_siswa[i]);
    }
}

void hapus_siswa(int index_siswa_keberapa) {
    memset(nama_siswa[index_siswa_keberapa],0,64);
    puts("Siswa telah dihapus");
    jumlah_siswa--;
}

// void edit_siswa()