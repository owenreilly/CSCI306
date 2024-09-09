
#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;

}

void to_uppercase(char *str){
    while (*str != '\0'){
        if (*str >= 'a' && *str <= 'z'){
            *str = *str - 32;
        }
        str++;
    }
}

int main(){
    int array_ref[5] = {1, 2, 3, 4, 5};
    int i = 0;
    int j = 4;
    printf("Before swap:\n");
    for(i = 0; i < 5; i++){
        printf("%d ", array_ref[i]);
    }
    printf("\n");

    swap(&array_ref[i],&array_ref[j]);
    printf("After swap:\n");
    for(i = 0; i < 5; i++){
        printf("%d ", array_ref[i]);
    }
    printf("\n");

    char str_ref[] = "Hello World!";
    printf("Before to_uppercase:\n");
    printf("%s\n", str_ref);
    to_uppercase(str_ref);
    printf("After to_uppercase:\n");
    printf("%s\n", str_ref);

    return 0;
}