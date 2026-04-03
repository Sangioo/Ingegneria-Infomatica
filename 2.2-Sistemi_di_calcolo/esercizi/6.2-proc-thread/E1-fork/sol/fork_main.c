#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) {
		printf("sono nel processo figlio\n");
	}
	else {
		printf("sono nel processo genitore\n");
	}
	return EXIT_SUCCESS;
}
