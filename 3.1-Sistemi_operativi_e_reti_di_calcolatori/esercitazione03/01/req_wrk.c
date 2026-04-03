#include "common.h"

#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <pthread.h>


// data array
int * data;
/** COMPLETE THE FOLLOWING CODE BLOCK
*
* Add any needed resource 
**/
int fd;
sem_t *req, *wrk;

int request() {
    /** COMPLETE THE FOLLOWING CODE BLOCK
     *
     * map the shared memory in the data array
     **/
    data = (int*) mmap(0, SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (data == MAP_FAILED) handle_error("request: mmap");

    printf("request: mapped address: %p\n", data);

    int i;
    for (i = 0; i < NUM; ++i) {
        data[i] = i;
    }
    printf("request: data generated\n");

    /** COMPLETE THE FOLLOWING CODE BLOCK
        *
        * Signal the worker that it can start the elaboration
        * and wait it has terminated
        **/
    printf("request: acquire updated data\n");
    sem_post(req);
    
    sem_wait(wrk);
    printf("request: updated data:\n");
    for (i = 0; i < NUM; ++i) {
        printf("%d\n", data[i]);
    }

    /** COMPLETE THE FOLLOWING CODE BLOCK
        *
        * Release resources
        **/
    sem_close(req);
    sem_close(wrk);

    return EXIT_SUCCESS;
}

int work() {
    /** COMPLETE THE FOLLOWING CODE BLOCK
     *
     * map the shared memory in the data array
     **/
    data = (int*) mmap(0, SIZE, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if (data == MAP_FAILED) handle_error("work: mmap");
    printf("worker: mapped address: %p\n", data);

    /** COMPLETE THE FOLLOWING CODE BLOCK
     *
     * Wait that the request() process generated data
     **/
    
    printf("worker: waiting initial data\n");
    sem_wait(req);

    printf("worker: initial data acquired\n");

    printf("worker: update data\n");
    int i;
    for (i = 0; i < NUM; ++i) {
        data[i] = data[i] * data[i];
    }

    printf("worker: release updated data\n");

    /** COMPLETE THE FOLLOWING CODE BLOCK
        *
        * Signal the requester that elaboration terminated
        **/
    sem_post(wrk);

    /** COMPLETE THE FOLLOWING CODE BLOCK
     *
     * Release resources
     **/
    sem_close(req);
    sem_close(wrk);
    close(fd);

    return EXIT_SUCCESS;
}



int main(int argc, char **argv){

   /** COMPLETE THE FOLLOWING CODE BLOCK
    *
    * Create and open the needed resources 
    **/
    shm_unlink(SHM_NAME);
    fd = shm_open(SHM_NAME, O_CREAT|O_EXCL|O_RDWR, 0666);
    if (fd < 0) handle_error("main: shm_open");
    
    int ret;
    ret = ftruncate(fd, SIZE);
    if (ret < 0) handle_error("main: ftruncate");

    sem_unlink(SEM_NAME_REQ);
    req = sem_open(SEM_NAME_REQ, O_CREAT|O_EXCL, 0666, 0);
    if (req == SEM_FAILED) handle_error("main: sem_open(req)");

    sem_unlink(SEM_NAME_WRK);
    wrk = sem_open(SEM_NAME_WRK, O_CREAT|O_EXCL, 0666, 0);
    if (wrk == SEM_FAILED) handle_error("main: sem_open(wrk)");

    pid_t pid = fork();
    if (pid == -1) {
        handle_error("main: fork");
    } else if (pid == 0) {
        work();
        _exit(EXIT_SUCCESS);
    }

    request();
    int status;
    ret = wait(&status);
    if (ret == -1)
      handle_error("main: wait");
    if (WEXITSTATUS(status)) handle_error_en(WEXITSTATUS(status), "request() crashed");


   /** COMPLETE THE FOLLOWING CODE BLOCK
    *
    * Close and release resources
    **/
    ret = close(fd);
    if (ret) handle_error("main: close");
    ret = shm_unlink(SHM_NAME);
    if (ret) handle_error("main: shm_unlink");
    ret = sem_unlink(SEM_NAME_REQ);
    if (ret) handle_error("main: sem_unlink(req)");
    ret = sem_unlink(SEM_NAME_WRK);
    if (ret) handle_error("main: sem_unlink(wrk)");

    _exit(EXIT_SUCCESS);

}
