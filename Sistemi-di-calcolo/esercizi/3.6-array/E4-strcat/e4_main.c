#include <stdio.h>

char* my_strcat(char* dest, const char* src);

int main() {
    char buf[] = "ham\0----------------";
    char* res = my_strcat(buf, "burger");
    printf("res=%s\n", res);
    return 0;
}
