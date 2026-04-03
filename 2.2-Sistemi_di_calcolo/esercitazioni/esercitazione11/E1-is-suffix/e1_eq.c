#include "e1.h"

int is_suffix(const char* s1, const char* s2) {
    const char *ecx = s1;
    const char *edx = s2;

    const char *edi = s1;
    const char *esi = s2;

W1:
    if (*ecx == 0) goto W1BIS;
    ecx++;
    goto W1;
W1BIS:
    ecx++;

W2:
    if (*edx == 0) goto W2BIS;
    edx++;
    goto W2;
W2BIS:
    edx++;

W3:
    if (edi == ecx) goto END;
    if (esi == edx) goto END;
    ecx--;
    edx--;
    if (*ecx != *edx) goto END;
    goto W3;

END:
    int ah = edi == ecx;
    int al = *ecx == *edx;
    ah &= al;
    return ah;
}