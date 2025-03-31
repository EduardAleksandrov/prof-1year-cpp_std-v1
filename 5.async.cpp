#include <iostream>
#include <vector>
#include <future>
#include <chrono>

void task(int id) {
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Имитация работы
    std::cout << "Task " << id << " completed." << std::endl;
}

int main() {
    const int numTasks = 5;
    std::vector<std::future<void>> futures;

    // Запускаем задачи
    for (int i = 0; i < numTasks; ++i) {
        futures.push_back(std::async(std::launch::async, task, i));
    }

    // Ожидаем завершения всех задач
    for (auto& future : futures) {
        future.get(); // Это блокирует выполнение до завершения задачи
    }

    std::cout << "All tasks completed." << std::endl;
    return 0;
}