#include "../e1A.h"

int slice(char* str, int start, int end, char* res)
{
    int ebx = 0;
    char* edi = str;
    int esi = end - start - 1;

L:;
    char cl = *edi;
    if (cl == 0) goto E;
    if (ebx != start) goto F;
    slice_helper(edi, esi, res);
F:
    ebx++;
    edi++;
    goto L;

E:;
    int eax = esi;
    if (ebx >= start) goto R;
    eax = 0;
R:
    return eax;
}