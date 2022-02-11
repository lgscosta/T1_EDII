#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stats.h"

struct stats{
    char sort;
    float counters[];
};

Stats* stats(char sort, int comparisons, int swaps, float time){
    Stats* stats = (Stats*) malloc(sizeof(Stats));
    stats->sort = sort;
    stats->counters[0] = comparisons;
    stats->counters[1] = swaps;
    stats->counters[2] = time;

    return stats;
}

char return_sort(Stats* stats){
    return stats->sort;
}

float* return_counters(Stats* stats){
    return stats->counters;
}

int return_comparisons(Stats* stats){
    return stats->counters[0];
}

int return_swaps(Stats* stats){
    return stats->counters[1];
}

float return_time(Stats* stats){
    return stats->counters[2];
}
void free_stats(Stats* stats){
    free(stats);
}