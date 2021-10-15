#include <stdio.h>

void print_triangle(int height) {
    for (int i = 0; i < height; i++) {
        for(int j = 0; j < height - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2*i-1; j++) {
            printf("#");
        }
        printf("\n");
    }
}

void sort_array(int *a, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {8, 4, 6, 2, 1};
    int size = 5;
    sort_array(arr, size);
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n"); 

    print_triangle(7);
}