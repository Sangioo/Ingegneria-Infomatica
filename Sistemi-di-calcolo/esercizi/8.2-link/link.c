#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// int link(const char* oldpath, const char* newpath)
// crea link hard newpath di file esistente oldpath

int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("sintassi: %s target link\n", argv[0]);
		return EXIT_FAILURE;
	}

	int res = link(argv[1], argv[2]);
	if (res == -1) {
		perror("link");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
