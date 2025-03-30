#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <functional>

class MyClass {
public:
    void memberFunction(int x) {
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Имитация длительной работы
        std::cout << "Значение: " << x << std::endl;
    }
};

int main() {
    MyClass obj;

    // Используем std::bind для передачи метода объекта
    auto boundFunction = std::bind(&MyClass::memberFunction, &obj, std::placeholders::_1);

    // Запускаем асинхронную задачу
    std::future<void> result = std::async(std::launch::async, boundFunction, 42);

    // Выполняем другие операции, пока задача выполняется
    std::cout << "Ожидание завершения задачи...\n";

    // Ждем завершения задачи
    result.get(); // Блокировка, пока задача не завершится

    return 0;
}