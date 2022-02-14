#ifndef statistics_h_
#define statistics_h_

typedef struct stats Stats;

// New stats
// The parameters are: letter of the sort type, number of comparisons, number of swaps, time spent
Stats* stats(char sort, int comparisons, int swaps, float time);

// Returns the sort type
// The parameters are: a stats
char return_sort(Stats* stats);

// Returns the counters buffer
// The parameters are: a stats
float* return_counters(Stats* stats);

// Returns the number of comparisons
// The parameters are: a stats
int return_comparisons(Stats* stats);

// Returns the number of stats
// The parameters are: a stats
int return_swaps(Stats* stats);

// Returns the time spent
// The parameters are: a stats
float return_time(Stats* stats);

// The parameters are: a stats
void free_stats(Stats* stats);

#endif /* statistics_h_ */