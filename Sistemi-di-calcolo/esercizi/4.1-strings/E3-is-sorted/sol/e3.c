#include "../e3.h"
#include <string.h>

int is_sorted(char *v[], int n) {
    int i;
    for (i=1; i<n; ++i)
        if (strcmp(v[i-1],v[i]) > 0) return -1;
    return 0;
}
