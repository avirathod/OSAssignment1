/*
* Avi Rathod
* CS 33211
* Assignment 1
*/

#include "shared.h"

int main() {
    int open = shm_open("/shared", O_RDWR, 0);

    struct sem *buff = mmap(NULL, sizeof(*buff), PROT_READ | PROT_WRITE, MAP_SHARED, open, 0);
    sem_post(&buff->empty);

    int o = 0;
    for (int i = 0; i < maxBuff; ++i) {
        sem_wait(&buff->full);
        char j = buff->buf[o];
        printf("Consumer got item on %d: %c\n", o, j);
        o = (o + 1) % minBuff;
        sem_post(&buff->empty);
    }
    shm_unlink("/shared");
    exit(EXIT_SUCCESS); 
}