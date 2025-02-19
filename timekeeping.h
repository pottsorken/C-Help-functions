
#include <sys/time.h>
#include <time.h>

/*
Will return the number of nano seconds between
t_start and t_stop and is used for benchmarking

Used like this:
    clock_gettime(CLOCK_MONOTONIC, &t_start);
    // What you want to benchmark
    clock_gettime(CLOCK_MONOTONIC, &t_stop);
    long result = nano_seconds(&t_start, &t_stop);
*/
long nano_seconds(struct timespec *t_start, struct timespec *t_stop)
{
    return (t_stop->tv_nsec - t_start->tv_nsec) +
           (t_stop->tv_sec - t_start->tv_sec) * 1000000000;
}