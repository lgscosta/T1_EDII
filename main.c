#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basics.h"

int main(int argc, char *argv[]){
    FILE* file;
    int* list; // List of numbers to ordenate
    int N; // Number of items
    int T = atoi(argv[2]); // Number of the "top T"

    //////////////////////////////////////////
    // argv[0] -> ./main.c                  //
    // argv[1] -> '-' and functions         //
    // argv[2] -> 'T' value to the "top T"  //
    // argv[3] -> path to the file          //
    //////////////////////////////////////////

    file = fopen(argv[3], "r");
    if(file == NULL){
        printf("Not able to open the file, please verify the path.\n");
        return 0;
    }

    // READING FILE
    fscanf(file, "%i", &N); // Assigning N

    list = (int*) malloc(N * sizeof(int)); // Allocating list size;

    for(int i = 0; i < N; i++){ // Filling list
        fscanf(file, "%i", &list[i]);
    }

    // READING FUNCTIONS
    manager(argv[1], list, N, T);

    // FREE
    free(list);
    fclose(file);
}


