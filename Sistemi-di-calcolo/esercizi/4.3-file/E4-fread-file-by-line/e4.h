#ifndef __LOAD_FILE_BY_LINE__
#define __LOAD_FILE_BY_LINE__

#include <stdlib.h>

int read_file_by_line(const char *filename, char ***lines, int *num_lines);
void deallocate_lines(char **lines, int num_lines);

#endif
