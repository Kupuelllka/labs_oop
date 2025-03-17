/*
    Гапонов Дмитрий 
    группа 5130904_30022
    Задание:
        Разработать программу, которая, используя только стандартные алгоритмы и функторы, 
        умножает каждый элемент списка чисел с плавающей  точкой на число PI

*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numbers>
#include <ranges>
#include <random>
#include <vector>

namespace setm {

// Функциональный объект, который умножает число на PI.
struct multiply_by_pi {
    double operator()(double x) const {
        return x * std::numbers::pi_v<double>;
    }
};

};  // namespace setm

int main() {
    // Генерация 5 случайных чисел в диапазоне [0.0, 5.0].
    static constexpr auto size{ 5 };
    static constexpr auto min_value{ 0.0 };
    static constexpr auto max_value{ 5.0 };
    std::random_device rd;
    std::mt19937 gen{ rd() };
    std::uniform_real_distribution dist{ min_value, max_value };
    std::vector<double> numbers(size);
    std::ranges::generate(numbers, [&] { return dist(gen); });

    // Вывод исходных чисел.
    std::cout << "Числа в исходном виде: ";
    std::ranges::copy(numbers, std::ostream_iterator<double>{ std::cout, " " });
    std::cout << '\n';

    // Умножение каждого числа на PI с использованием функционального объекта.
    std::ranges::transform(numbers, numbers.begin(), setm::multiply_by_pi());

    // Вывод результата: числа, умноженные на PI.
    std::cout << "Числа, умноженные на PI: ";
    std::ranges::copy(numbers, std::ostream_iterator<double>{ std::cout, " " });
    std::cout << '\n';
}