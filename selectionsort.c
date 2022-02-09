#include "selectionsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
int* selection_sort(int* list, int N, int comparison_count, int swap_count){
    int minimum = 0; // Variable to do the comparison
    int swap; // Variable to do the swap process
    
    comparison_count = 0; // Variable to count comparisons
    swap_count = 0; // Variable to count comparisons
  
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

    return list;
}
