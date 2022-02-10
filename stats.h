#ifndef statistics_h_
#define statistics_h_

typedef struct stats Stats;

Stats* stats(char* sort, int comparisons, int swaps, float time);

void print_stats(Stats* stats);

void free_stats(Stats* stats);

#endif /* statistics_h_ */