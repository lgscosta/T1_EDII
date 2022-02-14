#ifndef list_h_
#define list_h_

#include "stats.h"

typedef struct list List;

// Initialize the list
List* list_init();

// Add a new stats on the list
// The parameters are: list, stats
void new_stats(List*, Stats*);

// Prints the list on second format
// The parameters are: list
void print_list_second(List*);

// Prints the list on third format
// The parameters are: list, the path, the size of the list of ints, the size of the top
void print_list_third(List* list, char* path, int N, int T);

// Free the entire list
void free_list(List* list);

#endif /* list_h_ */