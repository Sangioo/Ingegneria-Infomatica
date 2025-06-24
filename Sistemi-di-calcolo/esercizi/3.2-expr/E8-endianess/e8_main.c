#include <stdio.h>

int main() {
   unsigned x = 0xDEADBEEF;
   unsigned char y = *(unsigned char*)&x;
   printf("%X\n", y);
   return 0;
}
