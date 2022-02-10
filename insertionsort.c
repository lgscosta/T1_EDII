#include "insertionsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void insertion_sort(int* list, int N, float* counters){
    clock_t begin = clock();
    int actual; // Variable to the actual number
    int previous; // Variable to the comparisson with the previous one
    int comparison_count = 0;
    int swap_count = 0;
    
    for (int i = 1; i < N; i++){ // Loop for all positions
        actual = list[i];
        previous = i - 1;

        // The comparison is gonna be (on each i of the loop) swap + 1
        comparison_count++;

        while (previous >= 0 && list[previous] > actual) { // If previous is == 0, it means that is the first of the list
                                                           // If list[previous] is bigger than actual, it shifts
            list[previous + 1] = list[previous]; // Swap
            previous--; // Previous is now the pre-previous
            swap_count++;
            comparison_count++;

        }
        
        list[previous + 1] = actual;
    }

    clock_t end = clock();
    float time_spent = ((float)(end - begin))/CLOCKS_PER_SEC;

    counters[0] = comparison_count;
    counters[1] = swap_count;
    counters[2] = time_spent;
}