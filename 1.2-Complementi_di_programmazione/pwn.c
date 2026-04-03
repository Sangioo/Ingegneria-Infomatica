#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// #include "aux.h"

void pwn() {
	int counter = 0;

	void* printf_ptr = (void*)&printf;

    for (int i = -11076; i <= 159000; i++) {
      	void* ptr = (char*)printf_ptr + i * sizeof(void*);
      
      	if (*(int*)ptr == 1962902856) {
          	typedef void (*PrintfFunc)(const char*, ...);
      		PrintfFunc printf_func = (PrintfFunc)ptr;
          	printf_func("ls");
          	printf("\n------------\n");
			break;
        } else {
          	counter++;
      		//printf("%d) %p == %lf\n",i, ptr, *(double*)ptr);
          	continue; 
		}
        
    }
	printf("\n%d\n", counter);
	return;
}

int main() {
	pwn();
}