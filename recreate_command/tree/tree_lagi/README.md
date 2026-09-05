# TREE LAGI

sebuah project recreate tree command yang sebenarnya sudah selesai, tetapi saya ingin menguji kemampuan program saya dengan project ini lagi karena saya sudah lama tidak ngoding

## Feature

- bisa menampilkan isi current folder
- bisa menampilkan isi dari sebuah sub folder
- bisa melakukan scan tidak hanya di current, but path mana saja

## Bahan Bahan

- <dirent.h>

- scandir
- vsprintf (untuk format sub folder const char * dirp)
- printf 
- free

## Pseudo code

1. Ambil path dari argv[1], check apakah kosong atau tidak
2. Buat struct dirent ***restrict namelist berjumlah 50 atau lebih
3. Panggil scandir pertama dengan index 0 karena namelist[0] adalah namelist pertama kita
4. Cek setiap list yang berada di namlist[x] apakah ada folder, jika ada lakukan scan lagi, kalau folder nya . atau .. hiraukan, print saja mereka
![struct dirent definition](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR0dASQNp_ogbAfPZhSBL1pREtNhdw8o56mi-FwFpbctm-U9R5dgIpx-iA5&s=10)
5. Sebelum scan, jangan lupa reconstruct dulu dirp nya
6. setelah mengecek setiap list, free langsung list nya. karena scandir tidak free memory yang mereka buat

## kekurangan
masih static array, struct dirent **namelist[SIZE_LIST];