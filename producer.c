/*
* Avi Rathod
* CS 33211
* Assignment 1
*/

#include "shared.h"

int main() {

    int open = shm_open("/shared", O_CREAT | O_EXCL | O_RDWR, S_IRUSR | S_IWUSR);
    struct sem *buff = mmap(NULL, sizeof(*buff), PROT_READ | PROT_WRITE, MAP_SHARED, open, 0);
    ftruncate(open, sizeof(struct sem));

    sem_init(&buff->empty, 1, 0);
    sem_init(&buff->full, 1, 0);
    
    char c = 'a';
    int j = 0;
    for (int i = 0; i < maxBuff; ++i) {
        sem_wait(&buff->empty);
        buff->buf[j] = c;
        printf("Producer sent item on %d: %c\n", j, c);
        j = (j + 1) % minBuff;
        ++c;
        sem_post(&buff->full);
    }
    shm_unlink("/shared"); 
    exit(EXIT_SUCCESS); 
}