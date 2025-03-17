/*
    Гапонов Дмитрий 
    группа 5130904_30022
    Вариант 2
    Задание:
        Реализуйте следующие классы
        • Контейнер, который содержит значения факториала от 1! до 10!. 
        Интерфейс класса должен включать в себя как минимум:
            ◦ Конструктор по умолчанию
            ◦ Функцию получения итератора указывающего на первый элемент контейнера - begin()
            ◦ Функцию получения итератора указывающего на элемент, следующий за последним - end()
        Доступ к элементам этого контейнера возможен только с помощью итераторов возвращаемых функциями begin() и end().
        Контейнер не должен содержать в памяти свои элементы, они должны вычисляться при обращении к ним через итератор
        • Класс итератора для перечисления элементов этого контейнера, объекты этого класса возвращаются функциями begin() и end(). Итератор должен быть двунаправленным. 
        Итератор должен быть совместимым с STL (проверить это можно используя алгоритм copy для копирования содержимого разработанного контейнера в vector<int>)
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class factorial_iterator {
public:
    factorial_iterator(int number)
        : n{ number } {}

    int operator*() const {
        int factorial{ 1 };
        for(int i{ 2 }; i <= n; ++i)
            factorial *= i;
        return factorial;
    }

    factorial_iterator& operator++() {
        ++n;
        return *this;
    }

    factorial_iterator operator++(int) {
        auto temp{ *this };
        ++(*this);
        return temp;
    }

    factorial_iterator& operator--() {
        --n;
        return *this;
    }

    factorial_iterator operator--(int) {
        auto temp{ *this };
        --(*this);
        return temp;
    }

    bool operator==(const factorial_iterator& other) const {
        return n == other.n;
    }

    bool operator!=(const factorial_iterator& other) const {
        return !(*this == other);
    }

private:
    int n;
};

class factorial_container {
public:
    factorial_container() = default;

    factorial_iterator begin() const {
        return factorial_iterator{ 1 };
    }

    factorial_iterator end() const {
        return factorial_iterator{ 11 };
    }
};

int main() {
    factorial_container container;

    std::vector<int> result;
    std::copy(container.begin(), container.end(), std::back_inserter(result));

    std::cout << "Factorials from 1! to 10!: ";
    for(auto factorial : result)
        std::cout << factorial << ' ';
    std::cout << '\n';
}
