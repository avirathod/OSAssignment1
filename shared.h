/*
* Avi Rathod
* CS 33211
* Assignment 1
*/

#include <sys/mman.h>
#include <fcntl.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define errExit(msg)    

do { 
    perror(msg); 
    exit(EXIT_FAILURE); \ 
} while (0)

#define minBuff 2
#define maxBuff 10

struct sem {
    pthread_mutex_t mutex;
    sem_t empty, full;
    char buf[minBuff];
};