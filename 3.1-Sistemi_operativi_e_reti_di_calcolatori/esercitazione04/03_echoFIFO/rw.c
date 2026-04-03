#include <asm-generic/errno-base.h>
#include <unistd.h>
#include <errno.h>
#include "common.h"


int readOneByOne(int fd, char* buf, char separator) {

    int ret;

    /** [TO DO] READ THE MESSAGE THROUGH THE FIFO DESCRIPTOR
     *
     * Suggestions:
     * - you can read from a FIFO as from a regular file descriptor
     * - since you don't know the length of the message, just
     *   read one byte at a time from the socket
     * - leave the cycle when 'separator' ('\n') is encountered
     * - repeat the read() when interrupted before reading any data
     * - return the number of bytes read
     * - reading 0 bytes means that the other process has closed
     *   the FIFO unexpectedly: this is an error that should be
     *   dealt with!
     **/
    int i = 0;
    do {
        ret = read(fd, buf + i, 1);

        if (ret == 0) handle_error("FIFO closed unexpectedly");

        if (ret <= 0) {
            if (errno == EINTR) continue;

            handle_error("Error in reading");
        }
    } while(buf[i++] != separator);
    return i;
}

void writeMsg(int fd, char* buf, int size) {

    int ret;
    /** [TO DO] SEND THE MESSAGE THROUGH THE FIFO DESCRIPTOR
     *
     * Suggestions:
     * - you can write on the FIFO as on a regular file descriptor
     * - make sure that all the bytes have been written: use a while
     *   cycle in the implementation as we did for file descriptors!
     **/
    int w_index = 0, to_send = size;
    while (to_send > 0) {
        ret = write(fd, buf + w_index, to_send);

        if (ret == 0) break;

        if (ret < 0) {
            if (errno == EINTR) continue;

            handle_error("Error while writing");
        }

        w_index += ret;
        to_send -= ret;
    }
}
