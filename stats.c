#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stats.h"

struct stats{
    char* sort;
    int comparisons;
    int swaps;
    float time;
};

Stats* stats(char* sort, int comparisons, int swaps, float time){
    Stats* stats = (Stats*) malloc(sizeof(Stats));
    stats->sort = sort;
    stats->comparisons = comparisons;
    stats->swaps = swaps;
    stats->time = time;

    return stats;
}

char* return_sort(Stats* stats){
    return stats->sort;
}

int return_comparisons(Stats* stats){
    return stats->comparisons;
}

int return_swaps(Stats* stats){
    return stats->swaps;
}

float return_time(Stats* stats){
    return stats->time;
}


void free_stats(Stats* stats){
    free(stats->sort);
    free(stats);
}