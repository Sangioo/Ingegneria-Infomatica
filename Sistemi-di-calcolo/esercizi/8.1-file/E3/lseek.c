#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>  

int main() {
    int fd = open("miofile.txt", O_RDONLY);
    if (fd == -1) {
        perror("error in open");
        return EXIT_FAILURE;
    }
    off_t o = lseek(fd, 0, SEEK_CUR);
    printf("Posizione iniziale: %ld\n", o);
    o = lseek(fd, -6, SEEK_END);
    printf("Posizione attuale: %ld\n", o);
    char buf[512];
    ssize_t r = read(fd, buf, sizeof(buf));
    if (r == -1) {
        perror("error in read");
        return EXIT_FAILURE;
    }
    printf("Letti %ld bytes\n", r);
    if (r > 0) {
        //fwrite(buf, sizeof(char), r, stdout);
        write(1, buf, r);
    }
    int res = close(fd);
    if (res == -1) {
        perror("error in close");
        return EXIT_FAILURE;
    }
}

