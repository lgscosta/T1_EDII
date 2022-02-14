#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stats.h"
#include "list.h"

// The cell tipe for the list 
typedef struct cell Cell;
struct cell{
    void* item;
    Cell* next;
};

struct list{
    Cell* first;
    Cell* last;
};

List* list_init(){
    List* list = (List*) malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;

    return list;
}

void new_stats(List* list, Stats* stats){
    Cell* cell = (Cell*) malloc(sizeof(Cell)); // Initialize the cell
    cell->item = stats; // Fill the cell
    cell->next = NULL; // Fill the cell

    // Putting on the list
    if(list->first == NULL){
        list->first = list->last = cell; // The only element of the list
    }

    list->last = list->last->next = cell; // Putting on the last position
}

void print_list_second(List* list){
    for(Cell* c = list->first; c != NULL; c = c->next){
        printf("Tempo de CPU:\t%.4f segundos\nComparações:\t%i\nTrocas:\t\t%i\n", return_time(c->item), return_comparisons(c->item), return_swaps(c->item));
        puts("\n");
    }
}

void print_list_third(List* list, char* path, int N, int T){
    
    for(Cell* c = list->first; c != NULL; c = c->next){
        printf("[algoritmo\tarquivo\ttam.\tT(top)\tcomp.\ttrocas\ttempo(s)]\n");

    switch (return_sort(c->item)){
        case 's': // Selection sort
            printf("Selection\t%s\t%i\t%i\t%i\t%i\t%.4f\n", path, N, T, return_comparisons(c->item), return_swaps(c->item), return_time(c->item));
            break;
        case 'i': // Insertion sort
            printf("Insertion\t%s\t%i\t%i\t%i\t%i\t%.4f\n", path, N, T, return_comparisons(c->item), return_swaps(c->item), return_time(c->item));
            break;
        case 'e': // Shell sort
            printf("Shell\t\t%s\t%i\t%i\t%i\t%i\t%.4f\n", path, N, T, return_comparisons(c->item), return_swaps(c->item), return_time(c->item));
            break;
        case 'q': // Quick sort
            printf("Quick\t\t%s\t%i\t%i\t%i\t%i\t%.4f\n", path, N, T, return_comparisons(c->item), return_swaps(c->item), return_time(c->item));
            break;
        case 'h': // Heap sort
            printf("Heap\t\t%s\t%i\t%i\t%i\t%i\t%.4f\n", path, N, T, return_comparisons(c->item), return_swaps(c->item), return_time(c->item));
            break;
        
        default:
            break;
        }
        
        puts("\n");
    }

}

void free_list(List* list){
    Cell* cell = list->first; // Auxiliary cell
    Cell* aux;

    while(cell != NULL){
        aux = cell->next;
        free(cell);
        cell = aux;
    }

    free(list);
}