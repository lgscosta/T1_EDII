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

void print_stats(Stats* stats){
    printf("%i  %i  %.4f", stats->comparisons, stats->swaps, stats->time);
}

void free_stats(Stats* stats){
    free(stats->sort);
    free(stats);
}