#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <omp.h>  // OpenMP header for omp_get_wtime()

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 1000;
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 9000 + 1000;
    }

    double start_time = omp_get_wtime();

    bubbleSort(arr, n);

    double end_time = omp_get_wtime();

    double time_taken = end_time - start_time;

    printf("Bubble sort of %d random 4-digit numbers took %f seconds.\n", n, time_taken);

    free(arr);
    return 0;
}
