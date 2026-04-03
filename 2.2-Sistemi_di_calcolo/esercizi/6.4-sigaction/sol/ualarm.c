#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int signum) {
	printf("Catturato SIGALRM\n");
}

int main() {
	struct sigaction act = {0};
	act.sa_handler = handler;
	int ret = sigaction(SIGALRM, &act, NULL);
	if (ret == -1) {
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	ualarm(500000,500000);

	unsigned i;
	for (i=0;i<10;i++)
		pause();

	return EXIT_SUCCESS;
}
