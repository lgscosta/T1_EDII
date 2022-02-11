#include "shellsort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void shell_sort(int *list, int N, float* counters){
    clock_t begin = clock();
    int actual; 
    int value;
    int key = 1;
    int comparison_count = 0;
    int swap_count = 0;

    while(key < N) {
        key = (3*key) +1;
    }

    while(key > 0){
        for(int i = key; i < N; i++){
            value = list[i];
            actual = i;

            while (actual > key-1 && value <= list[actual - key]) {
                comparison_count++;
                swap_count++;
                list[actual] = list[actual - key];
                actual = actual - key;
            }

            list[actual] = value;
        }

        key = key/3;
    }

    clock_t end = clock();
    float time_spent = ((float)(end - begin))/CLOCKS_PER_SEC;

    counters[0] = comparison_count;
    counters[1] = swap_count;
    counters[2] = time_spent;
}