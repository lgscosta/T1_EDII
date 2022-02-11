#include "heapsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void heap(int* list, int N, int actual, int comparison_count, int swap_count){
    int largest = actual; // Initialize largest as root
    int left = (2*actual + 1);
    int right = (2*actual + 2);
    int aux;

    // If left child is larger than root
    if (left < N && list[left] > list[largest]){
        comparison_count++;
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < N && list[right] > list[largest]){
        comparison_count++;
        largest = right;
    }

    // If largest is not root
    if (largest != actual){
        comparison_count++;
        swap_count++;
        aux = list[actual];
        list[actual] = list[largest];
        list[largest] = aux;

        // Recursively heap the affected sub-tree
        heap(list, N, largest, comparison_count, swap_count);
    }
}

// main function to do heap sort
void heap_sort(int* list, int N, float* counters){
    clock_t begin = clock();
    int aux;
    int comparison_count = 0;
    int swap_count = 0;

    // Build heap (rearrange array)
    for (int i = (N/2)-1; i >= 0; i--){
        heap(list, N, i, comparison_count, swap_count);
    }

    // One by one extract an element from heap
    for (int i = N-1; i > 0; i--){
        swap_count++;
        aux = list[0];
        list[0] = list[i];
        list[i] = aux;

        heap(list, i, 0, comparison_count, swap_count);
    }

    clock_t end = clock();
    float time_spent = ((float)(end - begin))/CLOCKS_PER_SEC;

    counters[0] = comparison_count;
    counters[1] = swap_count;
    counters[2] = time_spent;
}