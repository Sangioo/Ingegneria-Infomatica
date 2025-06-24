#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc < 2){
		printf ("pathname mancante\n");
		return EXIT_FAILURE;
	} 
	int res = unlink(argv[1]);
	if (res == -1) {
		perror("unlink");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
