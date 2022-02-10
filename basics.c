#include "basics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "selectionsort.h"
#include "insertionsort.h"
#include "shellsort.h"
#include "quicksort.h"
#include "heapsort.h"
#include "list.h"
#include "stats.h"

void manager(char* parameter, int* list, int N, int T, char* path_name){
    int index[3];
    float counters[3];
    int comparison_count = 0; // Variable to count comparisons
    int swap_count = 0; // Variable to count swaps
    float time;
    char algorithm;
    clock_t begin;
    clock_t end;

    int there_is_an_a = 0;

    memset(index, 0, sizeof(int));

    for(int i = 1; i < strlen(parameter); i++){ // Loop to read all parameters
                                                // > it starts with 1 to ignore the '-'
        switch (parameter[i]){
        case '1': // Top T
            index[0] = 1;
            break;

        
        case '2': // Stats
            index[1] = 1;
            break;

        
        case '3': // Tabulated stats
            index[2] = 1;
            break;

        
        case 'a': // All sorts
            there_is_an_a = 1;
            /* code */
            break;

        case 's': // Selection Sort
            selection_sort(list, N, counters);
            comparison_count = counters[0];
            swap_count = counters[1];
            time = counters[2];

            algorithm = 's';
            break;

        case 'i': // Insertion Sort
            insertion_sort(list, N, counters);
            comparison_count = counters[0];
            swap_count = counters[1];
            time = counters[2];

            algorithm = 'i';
            break;

        case 'e': // Shell Sort
            /* code */

            algorithm = 'e';
            break;

        case 'q': // Quick Sort
            quick_sort(list, 0, N-1, counters);
            comparison_count = counters[0];
            swap_count = counters[1];
            time = counters[2];

            algorithm = 'q';
            break;

        case 'h': // Heap Sort
            /* code */

            algorithm = 'h';
            break;
        
        default:
            break;
        }
        
    
    }

    if(there_is_an_a == 0){
        if(index[0] == 1){
            first_print_single(list, N, T);
        }

        if(index[1] == 1){
            second_print_single(time, comparison_count, swap_count);
        }

        if(index[2] == 1){
            third_print_single(algorithm, path_name, N, T, comparison_count, swap_count, time);
        }
    }

}

void first_print_single(int* list, int N, int T){
    int count = 0;

    for(int i = N-1; i > -1; i--){ 
        if(count > N){ // It will only happen in the case of 'T' being bigger than 'N'
            return;
        }

        printf("%i\n", list[i]);
        count++;

        if(count == T){ // Ends the loop
            return;
        }
    }

}

void second_print_single(float time, int comparisons, int swaps){
    printf("Tempo de CPU:\t%.4f segundos\nComparações:\t%i\nTrocas:\t\t%i\n", time, comparisons, swaps);
}

void third_print_single(char algorithm, char* path, int N, int T, int comparisons, int swaps, float time){
    printf("[algoritmo\tarquivo\ttam.\tT(top)\tcomp.\ttrocas\ttempo(s)]\n");

    switch (algorithm){
    case 's':
        printf("Selection\t%s\t%i\t%i\t%i\t%i\t%.4f\n", path, N, T, comparisons, swaps, time);
        break;
    case 'i':
        printf("Insertion\t%s\t%i\t%i\t%i\t%i\t%.4f\n", path, N, T, comparisons, swaps, time);
        break;
    case 'e':
        printf("Shell\t%s\t%i\t%i\t%i\t%i\t%.4f\n", path, N, T, comparisons, swaps, time);
        break;
    case 'q':
        printf("Quick\t\t%s\t%i\t%i\t%i\t%i\t%.4f\n", path, N, T, comparisons, swaps, time);
        break;
    case 'h':
        printf("Heap\t%s\t%i\t%i\t%i\t%i\t%.4f\n", path, N, T, comparisons, swaps, time);
        break;
    
    default:
        break;
    }
}