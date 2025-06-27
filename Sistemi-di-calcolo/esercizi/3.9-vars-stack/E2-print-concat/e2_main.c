#include <stdio.h>

void print_concat(const char* s[], int n);

int main() {
    const char* s[] = { "This", " is", " a ", "test", " to", " check",
                        " the correctness ", "of the", " program,",
                        " and ", "it succeeded." };

    print_concat(s, 11);

    return 0;
}
