#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>

class ReadersWriters {
private:
    std::mutex mtx; // Mutex for critical section
    std::condition_variable cv; // Condition variable for signaling
    int readers_count = 0; // Number of active readers
    bool writer_active = false; // Flag to indicate if a writer is active

public:
    void start_reading() {
        std::unique_lock<std::mutex> lock(mtx);
        // Wait until no writers are active
        cv.wait(lock, [this]() { return !writer_active; });
        readers_count++;
        lock.unlock();
    }

    void stop_reading() {
        std::lock_guard<std::mutex> lock(mtx);
        readers_count--;
        if (readers_count == 0) {
            cv.notify_all(); // Notify waiting writers
        }
    }

    void start_writing() {
        std::unique_lock<std::mutex> lock(mtx);
        // Wait until no readers or writers are active
        cv.wait(lock, [this]() { return readers_count == 0 && !writer_active; });
        writer_active = true;
        // The lock will be automatically released when the function exits

    }

    void stop_writing() {
        std::lock_guard<std::mutex> lock(mtx);
        writer_active = false;
        cv.notify_all(); // Notify waiting readers and writers
    }
};

void reader(ReadersWriters& rw, int id) {
    for (int i = 0; i < 3; ++i) {
        rw.start_reading();
        std::cout << "Reader " << id << " is reading." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate reading
        std::cout << "Reader " << id << " finished reading." << std::endl;
        rw.stop_reading();
        std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Simulate time between reads
    }
}

void writer(ReadersWriters& rw, int id) {
    for (int i = 0; i < 3; ++i) {
        rw.start_writing();
        std::cout << "Writer " << id << " is writing." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(150)); // Simulate writing
        std::cout << "Writer " << id << " finished writing." << std::endl;
        rw.stop_writing();
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate time between writes
    }
}

int main() {
    ReadersWriters rw;
    const int num_readers = 3;
    const int num_writers = 2;
    std::vector<std::thread> threads;

    // Create reader threads
    for (int i = 0; i < num_readers; ++i) {
        threads.emplace_back(reader, std::ref(rw), i);
    }

    // Create writer threads
    for (int i = 0; i < num_writers; ++i) {
        threads.emplace_back(writer, std::ref(rw), i);
    }

    // Wait for all threads to finish
    for (auto& th : threads) {
        th.join();
    }

    return 0;
}