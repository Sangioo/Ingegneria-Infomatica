#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	// si parte con un solo processo genitore
	printf("all'inizio sono il processo genitore con pid %d\n", getpid());
	pid_t pid = fork(); // genera clone (processo figlio)
	if (pid == -1) { // eseguito solo dal genitore perché clone non creato
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0) {
		printf("sono il processo figlio con pid %d e genitore %d\n",
			getpid(), getppid());
		_exit(EXIT_SUCCESS);
	} else {
		printf("sono il processo genitore con pid %d e genitore %d\n",
			getpid(), getppid());
	}

	pid_t t = wait(NULL);
	if (t == -1) {
		perror("wait");
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS; // vale zero
}

