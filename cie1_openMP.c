#include <stdio.h>
#include <stdlib.h>
#include <omp.h>   // For omp_get_wtime()
#include <time.h>  // For seeding rand()

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n = 10000; // Number of random 4-digit numbers
    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));

    // Generate random 4-digit numbers (1000 to 9999)
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 9000 + 1000;
    }

    double start = omp_get_wtime();

    mergeSort(arr, 0, n - 1);

    double end = omp_get_wtime();

    printf("Merge sort of %d random 4-digit numbers took %f seconds.\n", n, end - start);

    // Optional: print first 20 sorted numbers
    // printf("First 20 sorted numbers: ");
    // for (int i = 0; i < 20 && i < n; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    free(arr);
    return 0;
}
