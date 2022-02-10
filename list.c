#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stats.h"
#include "list.h"

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
    Cell* cell = (Cell*) malloc(sizeof(Cell));
    cell->item = stats;
    cell->next = NULL;

    if(list->first == NULL){
        list->first = list->last = cell;
    }

    list->last = list->last->next = cell;
}

void print_list_3(List* list){
    
    for(Cell* c = list->first; c != NULL; c = c->next){
        printf("[algoritmo\tarquivo\ttam.\tT(top)\tcomp.\ttrocas\ttempo(s)]\n");
    }
}

void free_list(List* list){
    Cell* cell = list->first;
    Cell* aux;

    while(cell != NULL){
        aux = cell->next;
        free(cell);
        cell = aux;
    }

    free(list);
}