#ifndef list_h_
#define list_h_

#include "stats.h"

typedef struct list List;

List* list_init();
void new_stats(List* list, Stats* stats);
void print_list_3(List* list);
void free_list(List* list);

#endif /* list_h_ */