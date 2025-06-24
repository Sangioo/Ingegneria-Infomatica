
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
		printf("sono nel processo figlio e termino con 25\n");
		_exit(25);
	}
	int status;
	pid = wait(&status);
	if (pid == -1) {
		perror("wait");
		exit(EXIT_FAILURE);
	}
	if (WIFEXITED(status))
		printf("il figlio ha restituito %d\n", WEXITSTATUS(status));
	return EXIT_SUCCESS;
}
