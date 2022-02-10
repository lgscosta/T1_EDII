#ifndef basics_h_
#define basics_h_

// The parameters are: string of flags, list of ints, size of list and size of the top and the path name
void manager(char*, int*, int, int, char*);

// The parameters are: list of ints, size of list and size of the top
void first_print_single(int*, int, int);

// The parameters are: time spent, number of comparisons and number of swaps
void second_print_single(float, int, int);

// The parameters are: algorithm key, path name, size of list, size of the top, number of comparisons,
// number of swaps and time spent
void third_print_single(char algorithm, char* path, int N, int T, int comparisons, int swaps, float time);

#endif /* basics_h_ */