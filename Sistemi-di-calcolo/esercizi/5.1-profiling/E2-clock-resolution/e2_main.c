#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>          // clock_gettime (nsec)
#include <sys/resource.h>  // getrusage (usec)

#define N 100
#define M 1
#define NC 200000
#define MC 2000

long get_user_time_msec() {
    struct rusage ru;
    getrusage(RUSAGE_SELF, &ru);
    return ru.ru_utime.tv_sec*1000000 + ru.ru_utime.tv_usec;
}

long get_real_time_nsec() {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec*1000000000+ts.tv_nsec;
}

// Since Linux 2.6.32; Linux-specific
#ifdef __linux__
long get_real_time_nsec_coarse() {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC_COARSE, &ts);
    return ts.tv_sec*1000000000+ts.tv_nsec;
}
#endif

void measure_usec(long *buf, unsigned n, unsigned m) {
    int i;
    printf("-------------------------------------------------\n");
    printf("Sampling usec...\n");
    for (i=0; i+3 < n; i+=4) {
        buf[i]   = get_user_time_msec();
        buf[i+1] = get_user_time_msec();
        buf[i+2] = get_user_time_msec();
        buf[i+3] = get_user_time_msec();
    }
    printf("Sampled values:\n");
    for (i=0; i<n; i+=m)
        printf("%-5d: %lu usec [getrusage]\n", i, buf[i]);
}

void measure_nsec(long *buf, unsigned n, unsigned m) {
    int i;
    printf("-------------------------------------------------\n");
    printf("Sampling nsec...\n");
    for (i=0; i+3 < n; i+=4) {
        buf[i]   = get_real_time_nsec();
        buf[i+1] = get_real_time_nsec();
        buf[i+2] = get_real_time_nsec();
        buf[i+3] = get_real_time_nsec();
    }
    printf("Sampled values:\n");
    for (i=0; i<n; i+=m)
        printf("%-5d: %lu nsec [clock_gettime(CLOCK_MONOTONIC)]\n", i, buf[i]);
}

#ifdef __linux__
void measure_nsec_coarse(long *buf, unsigned n, unsigned m) {
    int i;
    printf("-------------------------------------------------\n");
    printf("Sampling, nsec...\n");
    for (i=0; i+3 < n; i+=4) {
        buf[i]   = get_real_time_nsec_coarse();
        buf[i+1] = get_real_time_nsec_coarse();
        buf[i+2] = get_real_time_nsec_coarse();
        buf[i+3] = get_real_time_nsec_coarse();
    }
    printf("Sampled values:\n");
    for (i=0; i<n; i+=m)
        printf("%-5d: %lu nsec [clock_gettime(CLOCK_MONOTONIC_COARSE)]\n", i, buf[i]);
}
#endif

int main() {
    long *buf = malloc(N*sizeof(long));
    long *buf_nc = malloc(NC*sizeof(long));
    measure_usec(buf, N, M);
    measure_nsec(buf, N, M);
    #ifdef __linux__
    measure_nsec_coarse(buf_nc, NC, MC);
    #endif
    free(buf_nc);
    free(buf);

    struct timespec ts;
	clock_getres(CLOCK_MONOTONIC, &ts);
	printf("Resolution of CLOCK_MONOTONIC: %ld nsec\n", ts.tv_nsec);
	#ifdef __linux__
	clock_getres(CLOCK_MONOTONIC_COARSE, &ts);
	printf("Resolution of CLOCK_MONOTONIC_COARSE: %ld nsec\n", ts.tv_nsec);
	#endif
    return EXIT_SUCCESS;
}
