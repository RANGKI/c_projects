#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char my_str[64];
    void (*reverse_string)(int index);
} CustomString;

CustomString *bunch_of_strings[16];

void banner();
void create_string(int index);
int get_index();
void reverse_string(int index);
void check_nullbyte(char *my_str);
void show_string(int index);

int main(int argc, char **argv) {
    int choice;
    int index;

    banner();

    while(1) {
        printf("Input your choice : ");
        scanf("%d",&choice);
        putchar(10);
        if (choice == 1) {
            banner();
        } else if (choice == 2) {
            index = get_index();
            if (index != 0x1337) {
                create_string(index);
            } else {
                puts("Bad index");
            }
        } else if (choice == 3) {
            index = get_index();
            if (index != 0x1337) {
                show_string(index);
            } else {
                puts("Bad index");
            }
        } else if (choice == 4) {
            index = get_index();
            if (index != 0x1337) {
                bunch_of_strings[index]->reverse_string(index);
            } else {
                puts("Bad index");
            }
        } 
        
        else {
            puts("Invalid choice !");
        }
    }

    return 0;
}

void banner() {
    puts("=======================");
    puts("Ayyo, Custom string ???");
    puts("=======================");
    puts("1. Getting help");
    puts("2. Create your string");
    puts("3. Show your string");
    puts("4. Reverse your string");
    putchar(10);
}

void create_string(int index) {
    size_t new_line_index;
    if (bunch_of_strings[index] != NULL) {
        puts("Slot already occupied !\n");
        return;
    }
    bunch_of_strings[index] = malloc(sizeof(CustomString));
    printf("Enter your string [MAX 63]: ");
    fgets(bunch_of_strings[index]->my_str,sizeof(bunch_of_strings[index]->my_str),stdin);
    new_line_index = strcspn(bunch_of_strings[index]->my_str,"\n");
    if (new_line_index == sizeof(bunch_of_strings[index]->my_str) - 1) {
        bunch_of_strings[index]->my_str[new_line_index] = '\n';
    }
    check_nullbyte(bunch_of_strings[index]->my_str);
    new_line_index = strcspn(bunch_of_strings[index]->my_str,"\n");
    bunch_of_strings[index]->my_str[new_line_index] = '\0';
    bunch_of_strings[index]->reverse_string = &reverse_string;
    puts("String successfully created !\n");
}

int get_index() {
    int index;
    char c;

    printf("Enter Index: ");
    scanf("%d",&index);
    putchar(10);
    while ((c = getchar()) != '\n' && c != EOF);
    if (index >= 0 && index < 16) {
        return index;
    } else {
        return 0x1337;
    }
}

void reverse_string(int index) {
    if (bunch_of_strings[index] == NULL) {
        puts("Slot empty !\n\n");
        return;
    }
    int string_length;
    char *temp_copy;
    string_length = strlen(bunch_of_strings[index]->my_str);
    temp_copy = malloc(string_length);
    strncpy(temp_copy,bunch_of_strings[index]->my_str,string_length);
    for (int i = 0; i < string_length; i++) {
        bunch_of_strings[index]->my_str[i] = temp_copy[string_length - i - 1];
    }
    
    free(temp_copy);
    temp_copy = NULL;
    puts("String reversed !\n\n");
}

void check_nullbyte(char *my_str) {
    while(*my_str != '\n') {
        if (*my_str == 0) {
            puts("Fuck You");
            *my_str = 0x20;
        }
        my_str++;
    }
}

void show_string(int index) {
    if (bunch_of_strings[index] == NULL) {
        puts("Slot empty !\n\n");
        return;
    }
    puts("Heres Your String :");
    printf("1. %s\n\n",bunch_of_strings[index]->my_str);
}