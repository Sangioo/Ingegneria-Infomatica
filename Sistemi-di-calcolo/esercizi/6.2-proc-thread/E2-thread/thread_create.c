#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS     5

void * PrintHello(void *threadid){
   long tid;
   tid = (long)threadid;
   printf("Hello World! Sono il thread #%ld!\n", tid);
}

int main (int argc, char *argv[]){
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   for(t = 0; t < NUM_THREADS; t++) {
      printf("Funzione main: creo il thread %ld\n", t);
      rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
	   pthread_detach(threads[t]);
      if (rc) {
         printf("ERRORE: codice %d\n", rc);
         exit(-1);
      }
   }
   //sleep(2);
}
