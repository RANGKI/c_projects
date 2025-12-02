#include <stdio.h>
#include <stdlib.h>

typedef struct material_lock_in {
    int am_i;
    int week;
    char material[256];
} MaterialLockin;

void initialize_lockin(MaterialLockin *imMalloc);

int main() {
    MaterialLockin *im_malloc = malloc(sizeof(MaterialLockin));
    puts("WELCOME TO LOCK IN SIMULATOR");
    puts("PLEASE ENTER WHAT WOULD YOU LIKE TO LOCK TF IN");
    initialize_lockin(im_malloc);
    printf("with %d week and material %s i hope you can done this :> \n", im_malloc->week,im_malloc->material);
    free(im_malloc);
    return 0;
}

void initialize_lockin(MaterialLockin *imMalloc) {
    puts("WELCOME, WELCOME");
    printf("first enter are you ready to lock tf in type 1 for yes and other to no [x]: ");
    scanf("%d",&imMalloc->am_i);
    if (imMalloc->am_i != 1) {
        puts("Bro LOCK TF IN PLEASE !");
        exit(1);
    }
    puts("GREAT YOURE LOCK IN");
    puts("now tell me how long you want to lock in and the material !");
    printf("week : ");
    scanf("%d",&imMalloc->week);
    getchar();
    printf("material : ");
    fgets(imMalloc->material,sizeof(imMalloc->material),stdin);
    return;
}


// undefined8 main(void)

// {
//   void *__ptr;
  
//   __ptr = malloc(264);
//   puts("WELCOME TO LOCK IN SIMULATOR");
//   puts("PLEASE ENTER WHAT WOULD YOU LIKE TO LOCK TF IN");
//   initialize_lockin(__ptr);
//   printf("with %d week and material %s i hope you can done this :> \n",
//          (ulong)*(uint *)((long)__ptr + 4),(long)__ptr + 8);
//   free(__ptr);
//   return 0;
// }


// void initialize_lockin(int *param_1)

// {
//   puts("WELCOME, WELCOME");
//   printf("first enter are you ready to lock tf in type 1 for yes and other to no [x]: ");
//   __isoc99_scanf(&DAT_001020f5,param_1);
//   if (*param_1 != 1) {
//     puts("Bro LOCK TF IN PLEASE !");
//                     /* WARNING: Subroutine does not return */
//     exit(1);
//   }
//   puts("GREAT YOURE LOCK IN");
//   puts("now tell me how long you want to lock in and the material !");
//   printf("week : ");
//   __isoc99_scanf(&DAT_001020f5,param_1 + 1);
//   getchar();
//   printf("material : ");
//   fgets((char *)(param_1 + 2),0x100,stdin);
//   return;
// }

