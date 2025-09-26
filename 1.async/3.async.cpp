/*
*   Промис нужен для передачи данных между потоками 
*/
#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <stdexcept>

void asyncTask(std::promise<int>& prom) {
    try {
        std::this_thread::sleep_for(std::chrono::seconds(2)); // Имитация длительной работы
        
        // Здесь можно выбросить исключение для демонстрации обработки
        // throw std::runtime_error("Ошибка в задаче"); // Исключение
        
        // Если бы не было исключения, мы бы установили значение
        int result = 42;
        prom.set_value(result);
    } catch (...) {
        // Передача исключения в promise
        prom.set_exception(std::current_exception());
    }
}

int main() {
    // Создаем promise
    std::promise<int> prom;
    // Получаем связанный future
    std::future<int> fut = prom.get_future();

    // Запускаем асинхронную задачу в отдельном потоке
    std::thread t(asyncTask, std::ref(prom));

    // Выполняем другие операции, пока задача выполняется
    std::cout << "Ожидание результата...\n";

    try {
        // Получаем результат (блокировка, если результат еще не готов)
        int value = fut.get();
        std::cout << "Результат: " << value << std::endl;
    } catch (const std::exception& e) {
        // Обработка исключения, если оно было выброшено в потоке
        std::cout << "Поймано исключение: " << e.what() << std::endl;
    }

    // Ждем завершения потока
    t.join();

    return 0;
}