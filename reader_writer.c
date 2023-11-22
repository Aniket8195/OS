#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h> 
#include <stdint.h>
#include <unistd.h>

// Define the number of readers and writers
#define R 5
#define W 5

// Declare global variables
int readcount;
int writecount;

// Declare semaphores
sem_t wsem; // Protects the shared resource from concurrent writers
sem_t rsem; // Protects the readcount variable from concurrent access
pthread_mutex_t x; // Protects the shared resource from concurrent readers

// Declare a shared variable
int s = 5;

// Define the reader function
void *reader1(void *a) {
  // Get the reader ID
  int r = (intptr_t) a;

  // Iterate for 5 times
  for (int i = 0; i < 5; i++) {
    // Wait for the read semaphore
    sem_wait(&rsem);

    // Acquire the mutex lock
    pthread_mutex_lock(&x);

    // Increment the readcount
    readcount++;

    // If the readcount is 1, then wait for the write semaphore
    if (readcount == 1) {
      sem_wait(&wsem);
    }

    // Release the mutex lock
    pthread_mutex_unlock(&x);

    // Release the read semaphore
    sem_post(&rsem);

    // Read the shared variable
    printf("\t\tReader %d is reading: %d\n", r, s);

    // Acquire the mutex lock
    pthread_mutex_lock(&x);

    // Decrement the readcount
    readcount--;

    // If the readcount is 0, then post the write semaphore
    if (readcount == 0) {
      sem_post(&wsem);
    }

    // Release the mutex lock
    pthread_mutex_unlock(&x);

    // Sleep for a random amount of time
    sleep(rand() % 10);
  }
}

// Define the writer function
void *writer1(void *a) {
  // Get the writer ID
  int w = (intptr_t) a;

  // Iterate for 2 times
  for (int i = 0; i < 2; i++) {
    // Wait for the write semaphore
    sem_wait(&wsem);

    // Increment the writecount
    writecount++;

    // Write to the shared variable
    s += 5;
    printf("Writer %d is writing: %d\n", w, s);

    // Decrement the writecount
    writecount--;

    // Post the write semaphore
    sem_post(&wsem);

    // Sleep for a random amount of time
    sleep(rand() % 10);
  }
}

// Define the main function
int main() {
  // Initialize the semaphores
  sem_init(&wsem, 0, 1);
  sem_init(&rsem, 0, 1);

  // Initialize the mutex lock
  pthread_mutex_init(&x, NULL);

  // Create the reader and writer threads
  pthread_t thread_read[R];
  pthread_t thread_write[W];

  for (int i = 0; i < R; i++) {
    pthread_create(&thread_read[i], NULL, reader1, (void *) (intptr_t) i);
  }

  for (int i = 0; i < W; i++) {
    pthread_create(&thread_write[i], NULL, writer1, (void *) (intptr_t) i);
  }

  // Join all the threads
  for (int i = 0; i < R; i++) {
    pthread_join(thread_read[i], NULL);
  }

  for (int i = 0; i < W; i++) {
    pthread_join(thread_write[i], NULL);
  }

  // Destroy the semaphore and mutex lock
  sem_destroy(&wsem);
  sem_destroy(&rsem);
  pthread_mutex_destroy(&x);

  return 0;
}
