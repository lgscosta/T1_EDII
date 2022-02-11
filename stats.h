#ifndef statistics_h_
#define statistics_h_

typedef struct stats Stats;

Stats* stats(char sort, int comparisons, int swaps, float time);

char return_sort(Stats* stats);

float* return_counters(Stats* stats);

int return_comparisons(Stats* stats);

int return_swaps(Stats* stats);

float return_time(Stats* stats);

void free_stats(Stats* stats);

#endif /* statistics_h_ */