/*
    Гапонов Дмитрий 
    группа 5130904_30022
    Задание:
        Разработайте программу, которая
            a. Заполняет list<int> 15 случайными значениями от 1 до 20, список может содержать от 0 до 20 значений (обязательно проверить на длине списка 0, 1. 2, 3, 4, 5, 7, 14)
            b. Выводит содержимое списка в следующем порядке: первый элемент, последний элемент, второй элемент, предпоследний элемент, тритий элемент и т.д.
*/

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <list>
#include <iterator>
#include <stdexcept>
#include <string>
#include <utility>

namespace setm {

class priority_queue {
public:
    // Перечисление для уровней приоритета.
    enum class priority : uint8_t {
        LOW,     // Низкий приоритет.
        NORMAL,  // Обычный приоритет.
        HIGH    // Высокий приоритет.
    };

    // Структура элемента очереди.
    struct element {
        std::string name;  // Имя элемента.
    };

    using value_type = element;  // Тип элемента.

    // Конструктор с использованием списков инициализации для каждого уровня приоритета.
    priority_queue(std::initializer_list<value_type> elements_high = {},
                   std::initializer_list<value_type> elements_normal = {},
                   std::initializer_list<value_type> elements_low = {})
        : high{ elements_high }, normal{ elements_normal }, low{ elements_low } {}

    // Добавить элемент в очередь с указанным приоритетом.
    void put(value_type&& elem, priority prio) {
        auto& list{ get_list_for_priority(prio) };
        list.emplace_back(std::move(elem));
    }

    // Извлечь элемент с наивысшим приоритетом из очереди и удалить его.
    [[nodiscard]] value_type get() {
        auto& list{ get_non_empty_list() };
        auto value{ std::move(list.front()) };

        list.pop_front();
        return value;
    }

    // Переместить все элементы из низкого приоритета в высокий.
    void accelerate() {
        high.splice(high.end(), low);
    }

    // Получить общий размер очереди.
    [[nodiscard]] std::size_t size() const {
        return high.size() + normal.size() + low.size();
    }

    // Проверить, пуста ли очередь.
    [[nodiscard]] bool empty() const {
        return high.empty() && normal.empty() && low.empty();
    }

    // Вывести все элементы очереди с указанием их приоритета.
    void print() const {
        std::cout << "Элементы очереди:\n";
        std::cout << "C высоким приоритетом:\n";
        for(const auto& elem : high)
            std::cout << "  " << elem.name << '\n';

        std::cout << "С обычным приоритетом:\n";
        for(const auto& elem : normal)
            std::cout << "  " << elem.name << '\n';

        std::cout << "С низким приоритетом:\n";
        for(const auto& elem : low)
            std::cout << "  " << elem.name << '\n';
    }

private:
    // Получить список, соответствующий указанному приоритету.
    [[nodiscard]] std::list<value_type>& get_list_for_priority(priority prio) {
        switch(prio) {
            case priority::LOW: return low;
            case priority::NORMAL: return normal;
            case priority::HIGH: return high;
        }
        throw std::invalid_argument("Неверное значение приоритета");
    }

    // Получить первый непустой список в порядке приоритета.
    [[nodiscard]] std::list<value_type>& get_non_empty_list() {
        for(auto prio : { priority::HIGH, priority::NORMAL, priority::LOW })
            if(auto& list{ get_list_for_priority(prio) }; !list.empty())
                return list;

        throw std::out_of_range("Очередь пуста");
    }

    std::list<value_type> high;    // Список для высокого приоритета.
    std::list<value_type> normal;  // Список для обычного приоритета.
    std::list<value_type> low;     // Список для низкого приоритета.
};

}  // namespace setm

int main() {
    using namespace std::literals::string_literals;

    // Создание очереди с начальными элементами.
    setm::priority_queue pq = {
        { { "1"s }, { "2"s }, { "3"s } },  // Высокий приоритет.
        { { "4"s }, { "5"s }, { "6"s } },  // Обычный приоритет.
        { { "7"s }, { "8"s }, { "9"s } }   // Низкий приоритет.
    };

    // Вывод размера очереди и её содержимого.
    std::cout << "Размер очереди: " << pq.size() << '\n';
    pq.print();

    // Извлечение всех элементов из очереди.
    while(!pq.empty())
        std::cout << "Извлечённый элемент: " << pq.get().name << '\n';
    std::cout << "Размер очереди после извлечения: " << pq.size() << '\n';

    // Добавление новых элементов в очередь.
    pq.put({ "10"s }, setm::priority_queue::priority::LOW);
    pq.put({ "11"s }, setm::priority_queue::priority::NORMAL);
    pq.put({ "12"s }, setm::priority_queue::priority::HIGH);
    std::cout << "Размер очереди после добавления: " << pq.size() << '\n';
    pq.print();

    // Извлечение всех элементов из очереди.
    while(!pq.empty())
        std::cout << "Извлечённый элемент: " << pq.get().name << '\n';
    std::cout << "Размер очереди после извлечения: " << pq.size() << '\n';

    // Добавление новых элементов и ускорение (перемещение низкого приоритета в высокий).
    pq.put({ "13"s }, setm::priority_queue::priority::LOW);
    pq.put({ "14"s }, setm::priority_queue::priority::NORMAL);
    pq.put({ "15"s }, setm::priority_queue::priority::HIGH);
    std::cout << "Размер очереди после добавления: " << pq.size() << '\n';
    pq.print();

    pq.accelerate();
    std::cout << "Очередь после аксселирации: " << pq.size() << '\n';
    pq.print();

    // Извлечение всех элементов из очереди.
    while(!pq.empty())
        std::cout << "Извлечённый элемент: " << pq.get().name << '\n';
    std::cout << "Размер очереди после извлечения: " << pq.size() << '\n';
}