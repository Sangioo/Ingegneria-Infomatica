#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_THREADS	4

void * BusyWork(void * t) {
	int i;
	long tid;
	double result=0.0;
	tid = (long)t;
	printf("Thread %ld avviato...\n",tid);
	for (i=0; i<1000000; i++) {
		result += sin(i) * tan(i);
	}
	printf("Thread %ld terminato. Risultato = %e\n",tid, result);
	pthread_exit((void*) t);
}

int main (int argc, char *argv[]) {
	pthread_t thread[NUM_THREADS];
	int rc;
	long t;
	void *status;

	for(t=0; t<NUM_THREADS; t++) {
    	printf("Main: creo il thread %ld\n", t);
      	rc = pthread_create(&thread[t], NULL, BusyWork, (void *)t); 
      	if (rc) {
        	printf("ERROR; return code da pthread_create() %d\n", rc);
         	exit(-1);
        }
    }

	for(t=0; t<NUM_THREADS; t++) {
    	rc = pthread_join(thread[t], &status);
    	if (rc) {
        	printf("ERROR; return code da pthread_join() %d\n", rc);
         	exit(-1);
        }
      	printf("Main: ho completato il join con il thread %ld uscito con stato %ld\n",t,(long)status);
    }
 	printf("Main: programma terminato.\n");
}
