#include <stdlib.h>
#include <stdio.h>
#include <time.h>       	// clock_gettime
#include <sys/resource.h>   // getrusage

long get_real_time_nsec() {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec*1000000000+ts.tv_nsec;
}

#define N 5000000

void measure_getrusage(unsigned n) {
    int i;
	struct rusage ru;
    printf("-------------------------------------------------\n");
    printf("Measuring getrusage...\n");
    long start = get_real_time_nsec();
    for (i=0; i+3 < n; i+=4) {
        getrusage(RUSAGE_SELF, &ru);
        getrusage(RUSAGE_SELF, &ru);
        getrusage(RUSAGE_SELF, &ru);
        getrusage(RUSAGE_SELF, &ru);
    }
    long elapsed = get_real_time_nsec()-start;
    printf("Time per getrusage: %f nsec\n", (double)elapsed/n);
}

void measure_clock_gettime(unsigned n) {
    int i;
	struct timespec ts;
    printf("-------------------------------------------------\n");
    printf("Measuring clock_gettime...\n");
    long start = get_real_time_nsec();
    for (i=0; i+3 < n; i+=4) {
        clock_gettime(CLOCK_MONOTONIC, &ts);
        clock_gettime(CLOCK_MONOTONIC, &ts);
        clock_gettime(CLOCK_MONOTONIC, &ts);
        clock_gettime(CLOCK_MONOTONIC, &ts);
    }
    long elapsed = get_real_time_nsec()-start;
    printf("Time per clock_gettime: %f nsec\n", (double)elapsed/n);
}

// Since Linux 2.6.32; Linux-specific
#ifdef __linux__
void measure_clock_gettime_coarse(unsigned n) {
    int i;
	struct timespec ts;
    printf("-------------------------------------------------\n");
    printf("Measuring clock_gettime [coarse]...\n");
    long start = get_real_time_nsec();
    for (i=0; i+3 < n; i+=4) {
        clock_gettime(CLOCK_MONOTONIC_COARSE, &ts);
        clock_gettime(CLOCK_MONOTONIC_COARSE, &ts);
        clock_gettime(CLOCK_MONOTONIC_COARSE, &ts);
        clock_gettime(CLOCK_MONOTONIC_COARSE, &ts);
    }
    long elapsed = get_real_time_nsec()-start;
    printf("Time per clock_gettime: %f nsec\n", (double)elapsed/n);
}
#endif

int main() {
    measure_getrusage(N);
    measure_clock_gettime(N);
    #ifdef __linux__
    measure_clock_gettime_coarse(N);
    #endif
    return EXIT_SUCCESS;
}
