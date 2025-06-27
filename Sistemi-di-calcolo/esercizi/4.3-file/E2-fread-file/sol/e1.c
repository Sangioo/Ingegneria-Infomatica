#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "../e1.h"

#define USA_FILE 1

int read_file(char *filename, void **buffer, size_t *size){

#if USA_FILE
    FILE* fd = NULL;
    *size = 0;
    *buffer = NULL;
    int res;

    fd = fopen(filename, "rb" /* read */);
    if (fd == NULL) goto cleanup;

    res = fseek(fd,0,SEEK_END);
    if (res == -1) goto cleanup;

    *size = ftell(fd);
    if (*size == -1) goto cleanup;

    *buffer = malloc(*size);
    if (*buffer == NULL) goto cleanup;

    res = fseek(fd,0,SEEK_SET);
    if (res == -1) goto cleanup;

    res = fread(*buffer, 1, *size, fd);
    if (res != *size) goto cleanup;

    res = fclose(fd);
    if (res == EOF) goto cleanup;

    return 0;

cleanup:;
    int old_errno = errno;
    if (fd != NULL) fclose(fd);
    if (*buffer != NULL) free(*buffer);
    errno = old_errno;
    return -1;

#else

    int fd = -1;
    *size = 0;
    *buffer = NULL;
    int res;

    fd = open(filename, O_RDONLY);
    if (fd == -1) goto cleanup;

    res = lseek(fd, 0, SEEK_END);
    if (res == -1) goto cleanup;

    *size = lseek(fd, 0, SEEK_CUR);
    if (*size == -1) goto cleanup;

    *buffer = malloc(*size);
    if (*buffer == NULL) goto cleanup;

    res = lseek(fd, 0, SEEK_SET);
    if (res == -1) goto cleanup;

    res = read(fd, *buffer, *size);
    if (res != *size) goto cleanup;

    res = close(fd);
    if (res == -1) goto cleanup;
    
    return 0;

cleanup:;
    int old_errno = errno;
    if (fd >= 0) close(fd);
    if (*buffer != NULL) free(*buffer);
    errno = old_errno;
    return -1;
#endif
}