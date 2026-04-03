#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define BUF_SIZE 600000000
#define TRIALS 50

double get_real_time_msec() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec*1E03 + ts.tv_nsec*1E-06;
}

int main(int argc, char* argv[]) {

	if (argc < 2) {
		fprintf(stderr, "syntax: %s [displacement]\n", argv[0]);
		return -1;
	}

	int displacement = atoi(argv[1]);

	char* buf = malloc(BUF_SIZE);
	assert(buf != NULL);

	int i, k;

    double start = get_real_time_msec();

	for (k=0;k<TRIALS;++k) 
		for (i=0; i + sizeof(long) + displacement < BUF_SIZE; i+=sizeof(long))
			(*(long*)(buf + i + displacement))++;

    double elapsed = get_real_time_msec() - start;

    printf("Displacement: %d - Elapsed: %.3f\n", displacement, elapsed/TRIALS);

	free(buf);

	return 0;
}
