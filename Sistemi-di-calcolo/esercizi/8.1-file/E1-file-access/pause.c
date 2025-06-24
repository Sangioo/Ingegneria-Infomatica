#include <stdio.h>
#include <unistd.h>

int main() {
    FILE* fd = fopen("miofile.txt", "w");
	pause();
    fclose(fd);
}
