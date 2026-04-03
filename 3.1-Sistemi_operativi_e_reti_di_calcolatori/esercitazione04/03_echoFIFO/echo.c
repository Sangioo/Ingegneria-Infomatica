// #include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> // mkfifo()
#include <sys/stat.h>  // mkfifo()

#include "common.h"
// #include "rw.c"

/** Echo component **/
int main(int argc, char* argv[]) {
    int ret;
    int echo_fifo, client_fifo;
    int bytes_left, bytes_sent, bytes_read;
    char buf[1024];

    char* quit_command = QUIT_COMMAND;
    size_t quit_command_len = strlen(quit_command);

    // Create the two FIFOs
    unlink(ECHO_FIFO_NAME);
    ret = mkfifo(ECHO_FIFO_NAME, 0666);
    if(ret) handle_error("Cannot create Echo FIFO");

    unlink(CLNT_FIFO_NAME);
    ret = mkfifo(CLNT_FIFO_NAME, 0666);
    if(ret) handle_error("Cannot create Client FIFO");

    /** INSERT CODE HERE TO OPEN THE TWO FIFOS
     *
     * Suggestions:
     * - the two FIFOs should be opened in the same order in both the
     *   Echo and the Client programs to avoid deadlocks
     * - open in 'O_WRONLY' or 'O_RDONLY' mode to fullfil the following
     *   requirement: the Echo program sends data through 'echo_fifo'
     *   and the Client program does it through 'client_fifo'
     **/
    echo_fifo = open(ECHO_FIFO_NAME, O_WRONLY);
    if (echo_fifo < 0) handle_error("Cannot open Echo FIFO");

    client_fifo = open(CLNT_FIFO_NAME, O_RDONLY);
    if (client_fifo < 0) handle_error("Cannot open Client FIFO");

    // send welcome message
    sprintf(buf, "Hi! I'm an Echo process based on FIFOs. I will send you back through a FIFO whatever"
            " you send me through the other FIFO, and I will stop and exit when you send me %s.\n", quit_command);
    bytes_left = strlen(buf);
    bytes_sent = 0;
    /** INSERT CODE HERE TO SEND THE MESSAGE THROUGH THE ECHO FIFO
     *
     * Suggestions:
     * - you can write on the FIFO as on a regular file descriptor
     * - make sure that all the bytes have been written: use a while
     *   cycle in the implementation as we did for file descriptors!
     **/
    writeMsg(echo_fifo, buf, bytes_left);

    while (1) {
        /** INSERT CODE HERE TO READ THE MESSAGE THROUGH THE CLIENT FIFO
         *
         * Suggestions:
         * - you can read from a FIFO as from a regular file descriptor
         * - since you don't know the length of the message, just try
         *   to read the data available in the FIFO (and make sure that
         *   we have enough room to add a string terminator later)
         * - repeat the read() when interrupted before reading any data
         * - store the number of bytes read in 'bytes_read'
         * - reading 0 bytes means that the other process has closed
         *   the FIFO unexpectedly: this is an error to deal with!
         **/
        bytes_read = readOneByOne(client_fifo, buf, '\n');

        if (DEBUG) {
            buf[bytes_read] = '\0';
            printf("Message received: '%s'\n", buf);
        }

        // check whether I have just been told to quit...
        if (bytes_read - 1 == quit_command_len && !memcmp(buf, quit_command, quit_command_len)) break;

        // ... or if I have to send the message back through the Echo FIFO
        bytes_left = bytes_read;
        bytes_sent = 0;
        /** INSERT CODE HERE TO SEND THE MESSAGE THROUGH THE ECHO FIFO
         *
         * Suggestions:
         * - you can write on the FIFO as on a regular file descriptor
         * - make sure that all the bytes have been written: use a while
         *   cycle in the implementation as we did for file descriptors!
         **/
         writeMsg(echo_fifo, buf, bytes_left);
    }

    // close the descriptors
    ret = close(echo_fifo);
    if(ret) handle_error("Cannot close Echo FIFO");
    ret = close(client_fifo);
    if(ret) handle_error("Cannot close Client FIFO");

    // destroy the two FIFOs
    ret = unlink(ECHO_FIFO_NAME);
    if(ret) handle_error("Cannot unlink Echo FIFO");
    ret = unlink(CLNT_FIFO_NAME);
    if(ret) handle_error("Cannot unlink Client FIFO");
    exit(EXIT_SUCCESS);
}
