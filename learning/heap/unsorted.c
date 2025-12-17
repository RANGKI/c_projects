#include <stdlib.h>
#include <stdio.h>

int main() {
    void *ptr[9];

    // Allocate 8 chunks of the same size
    for (int i = 0; i < 9; i++)
        ptr[i] = malloc(550);

    // Free first 7 -> tcache for 0x230 size is now full (7 entries)
    for (int i = 0; i < 7; i++)
        free(ptr[i]);

    // Free the 8th -> this one goes to UNSORTED BIN because tcache is full
    free(ptr[7]);
    printf("%s\n",ptr[7]);
    free(ptr[8]);
    printf("%s\n",ptr[8]);


    // stop here and inspect with gdb/pwndbg
    for (;;); // keep program alive for inspection
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// int main() {
    
//     // void *ptr[8];
//     // for (int i = 0; i < 7; i++) {
//     // ptr[i] = malloc(550);
//     // }
//     // for (int i = 0; i < 7; i++) {
//     //     free(ptr[i]);
//     // }

//     // int size;
//     // void *tes;
//     // while(1) {
//     //     scanf("%d",&size);
//     //     if(size == 0) {
//     //         break;
//     //     }
//     //     tes = malloc(size);
//     //     free(tes);
//     // }
//     // puts("NOW IS THE SHOW");
//     // write(1,tes,40);
//     // return 0;
// }