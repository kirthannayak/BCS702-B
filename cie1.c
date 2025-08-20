#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n = 1000; // Number of random 4-digit numbers
    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));

    // Generate random 4-digit numbers (1000 to 9999)
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 9000 + 1000;
    }

    // Record start time
    clock_t start = clock();

    // Bubble sort
    bubbleSort(arr, n);

    // Record end time
    clock_t end = clock();

    // Calculate elapsed time in seconds
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;


    printf("Bubble sort of %d random 4-digit numbers took %f seconds.\n", n, time_spent);

    free(arr);
    return 0;
}
