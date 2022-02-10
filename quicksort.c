#include "quicksort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void quick_sort(int* list, int first, int last, float* counters){
    clock_t begin = clock();
    int comparison_count = 0;
    int swap_count = 0;
    int buffer[last - first + 1]; // Auxiliary buffer
    int top = -1; // Variable to control the top of the buffer
    int swap;
 
    buffer[++top] = first; // buffer[0]
    buffer[++top] = last; // buffer[1]
 
    while (top >= 0){ // Not empty
        last = buffer[top--];
        first = buffer[top--];

        int ending = list[last];
        int previous = (first - 1);
        int aux;
    
        for (int i = first; i <= last - 1; i++) {
            if (list[i] <= ending){
                comparison_count++;
                previous++;

                swap_count++;
                aux = list[previous];
                list[previous] = list[i];
                list[i] = aux;
            }
        }

        swap_count++;
        aux = list[previous + 1];
        list[previous + 1] = list[last];
        list[last] = aux;

        swap = previous + 1;

        if (swap - 1 > first){
            buffer[++top] = first;
            buffer[++top] = swap - 1;
        }

        if (swap + 1 < last){
            buffer[++top] = swap + 1;
            buffer[++top] = last;
        }
    }

    clock_t end = clock();
    float time_spent = ((float)(end - begin))/CLOCKS_PER_SEC;

    counters[0] = comparison_count;
    counters[1] = swap_count;
    counters[2] = time_spent;
}