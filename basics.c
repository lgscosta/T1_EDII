#include "basics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "selectionsort.h"
#include "insertionsort.h"
#include "shellsort.h"
#include "quicksort.h"
#include "heapsort.h"

void manager(char* parameter, int* list, int N, int T){
    int index[3];
    memset(index, 0, sizeof(int));

    for(int i = 1; i < strlen(parameter); i++){ // Loop to read all parameters
                                                // > it starts with 1 to ignore the '-'
        if(atoi(&parameter[i]) == 1 || atoi(&parameter[i]) == 2 || atoi(&parameter[i]) == 3){ // Only if it's a number
            switch (atoi(&parameter[i])){
            case 1: // Top T
                index[0] = 1;
                break;

            case 2: // Stats
                index[1] = 1;
                break;

            case 3: // Tabulated stats
                index[2] = 1;
                break;
            
            default:
                break;
            }
        }
        else{ // Only if it's a letter
            switch (parameter[i]){
            case 'a': // All sorts
                /* code */
                break;

            case 's': // Selection Sort
                /* code */
                break;

            case 'i': // Insertion Sort
                /* code */
                break;

            case 'e': // Shell Sort
                /* code */
                break;

            case 'q': // Quick Sort
                /* code */
                break;

            case 'h': // Heap Sort
                /* code */
                break;
            
            default:
                break;
            }
        
        }
    
    }

    if(list[0] == 1){
        // first_print
    }

    if(list[1] == 1){
        // second_print
    }

    if(list[2] == 1){
        // third_print
    }

}

void first_print(int* list, int N, int T){
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