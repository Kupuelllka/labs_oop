/*
    Гапонов Дмитрий 
    группа 5130904_30022
    Задание:
        Реализовать этот класс, используя list или deque. Объяснить свой выбор.
        Протестируете программу, добавьте отладочный вывод, показывающий, что  класс работает правильно.
*/

#include <algorithm>
#include <list>
#include <iostream>
#include <random>


int main() {
    std::list<int> l; // Создаем список целых чисел

    // Проходим по различным размерам списка
    for(auto sz : { 0, 1, 2, 3, 4, 5, 7, 14 }) {
        l.clear(); // Очищаем список
        l.resize(sz); // Устанавливаем размер списка

        std::cout << "Размер списка: " << l.size() << '\n';

        // Заполняем список случайными числами от 0 до 20
        std::generate(l.begin(), l.end(), [] {
            static std::default_random_engine gen{ std::random_device{}() };
            static std::uniform_int_distribution<int> int_dist{ 0, 20 };

            return int_dist(gen);
        });

        // Выводим список в прямом порядке
        std::cout << "Список в прямом порядке: ";
        for(auto i : l)
            std::cout << i << ' ';
        std::cout << '\n';

        // Выводим список в зигзагообразном порядке
        std::cout << "Список в зигзагообразном порядке:   ";
        auto begin{ l.begin() }; // Итератор на начало списка
        auto end{ std::prev(l.end()) }; // Итератор на конец списка (предыдущий элемент от end)
        for(std::size_t i{}; i < l.size() / 2; ++i) {
            std::cout << *begin++ << ' ' << *end-- << ' ';
        }

        // Если список имеет нечетное количество элементов, выводим последний элемент
        if(l.size() % 2 != 0)
            std::cout << *begin;

        std::cout << '\n';

        std::cout << "----------------------------------------\n";
    }
}