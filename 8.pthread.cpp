#include <iostream>
#include <pthread.h>
#include <unistd.h> // For sleep function

// Function to be executed by the thread
void* printNumbers(void* arg) {
    int id = *((int*)arg); // Cast the argument to an integer pointer and dereference it
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Thread " << id << ": " << i << std::endl;
        sleep(1); // Sleep for 1 second
    }
    return nullptr; // Return NULL
}

int main() {
    pthread_t thread1, thread2; // Thread identifiers
    int id1 = 1, id2 = 2; // Thread IDs to pass as arguments

    // Create two threads
    pthread_create(&thread1, nullptr, printNumbers, (void*)&id1);
    pthread_create(&thread2, nullptr, printNumbers, (void*)&id2);

    // Wait for both threads to finish
    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);

    std::cout << "Both threads have finished execution." << std::endl;

    return 0;
}