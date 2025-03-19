#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

void merge(int arr[], int low, int high, int mid) {
    int i, j, k;
    int size = high - low + 1;
    int c[SIZE];
    i = low;
    j = mid + 1;
    k = 0;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            c[k++] = arr[i++];
        } else {
            c[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        c[k++] = arr[i++];
    }

    while (j <= high) {
        c[k++] = arr[j++];
    }

    for (i = low, k = 0; i <= high; i++, k++) {
        arr[i] = c[k];
    }

}

void merge_sort(int arr[], int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, high, mid);
}

void generate_random_array(int arr[], int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = (rand() % (max - min + 1)) + min;
    }
}

int main() {
    int arr[SIZE];

    srand(time(NULL));
    generate_random_array(arr, SIZE, 1, 1000);

    /*printf("Original array (first 10 elements):\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");*/

    clock_t start = clock();
    merge_sort(arr, 0, SIZE - 1);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted array:\n");
    for (int i = 0; i <SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Time taken: %f seconds\n", time_taken);



    return 0;
}
