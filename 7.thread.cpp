#include <iostream>
#include <thread>
#include <chrono>

// Function to be executed by the thread
void printNumbers(int id) {
    for (int i = 1; i <= 5; ++i) {
        std::cout << "Thread " << id << ": " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Sleep for 500 milliseconds
    }
}

int main() {
    // Create two threads
    std::thread thread1(printNumbers, 1);
    std::thread thread2(printNumbers, 2);

    // Wait for both threads to finish
    thread1.join();
    thread2.join();

    std::cout << "Both threads have finished execution." << std::endl;

    return 0;
}