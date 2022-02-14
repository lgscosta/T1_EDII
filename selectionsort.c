#include "selectionsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
  
void selection_sort(int* list, int N, float* counters){
    clock_t begin = clock(); // Starts the clock
    int minimum = 0; // Variable to do the comparison
    int swap; // Variable to do the swap process
    int comparison_count = 0;
    int swap_count = 0;
  
    for (int i = 0; i < N-1; i++){ // Loop for all positions except the last one
        minimum = i; 

        for (int j = i+1; j < N; j++){ // Loop for all positions except the first
          if (list[j] < list[minimum]){
            minimum = j; 
          }
          comparison_count++; // One more comparison
        }

        // At the end the minimum will be the smaller int
        // Swap the positions
        swap = list[minimum];
        list[minimum] = list[i];
        list[i] = swap;
        swap_count++; // One more swap
    }

    clock_t end = clock(); // Finishes the clock
    float time_spent = ((float)(end - begin))/CLOCKS_PER_SEC; // Calculate on seconds

    // To return 
    counters[0] = comparison_count;
    counters[1] = swap_count;
    counters[2] = time_spent;
}
