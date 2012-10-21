#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void die(const char *message){
    if (errno){
        perror(message);
    } else {
        printf("Error: %p", message);
    }
}

typedef int (*compare_cb)(int a, int b);

void bubble_sort(int *numbers, int count, compare_cb cmp){
    int temp = 0;
    int i = 0;
    int j = 0;

    for (i = 0; i < count; i++){
        for (j = 0; j < count - 1; j++){
            if (cmp(numbers[j], numbers[j + 1]) > 0){
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

int sorted_order(int a, int b){
    return a - b;
}

int reverse_order(int a, int b){
    return b - a;
}

void test_sorting(int *numbers, int count, compare_cb cmp){
    bubble_sort(numbers, count, cmp);

    /*
    if (!sorted) die("Failure to sorted");
    */

    int i = 0;
    for (i = 0; i < count; i++){
        printf("%d ", numbers[i]);
    }

    printf("\n");
    

}

int main(int argc, char *argv[]){
    if (argc < 1) die("USAGE: ex18.o 12 13 0 3");

    int count;
    count = argc - 1;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));
    if (!numbers) die("Memory error!");

    int i = 0;
    for(i = 0; i < count; i++){
        numbers[i] = atoi(*(inputs + i));
    }

    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);

    free(numbers);
    return 0;

}
