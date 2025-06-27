#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void handler(int signum) {
	printf("Catturato SIGINT\n");
}

int main() {
	struct sigaction act = {0};
	act.sa_handler = handler; // SIG_IGN;
	int ret = sigaction(SIGINT, &act, NULL);
	if (ret == -1) {
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	unsigned i = 0;
	while (i++ >= 0) {
		if (i % 1000000000 == 0)
			printf("0xDEADBEEF...\n");
	}

	return EXIT_SUCCESS;
}