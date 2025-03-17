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

// Function object that multiplies a number by PI.
struct multiply_by_pi {
    double operator()(double x) const {
        return x * std::numbers::pi_v<double>;
    }
};

};  // namespace setm

int main() {
    // Generate 5 random numbers in [0.0, 5.0].
    static constexpr auto size{ 5 };
    static constexpr auto min_value{ 0.0 };
    static constexpr auto max_value{ 5.0 };
    std::random_device rd;
    std::mt19937 gen{ rd() };
    std::uniform_real_distribution dist{ min_value, max_value };
    std::vector<double> numbers(size);
    std::ranges::generate(numbers, [&] { return dist(gen); });

    // Print original numbers.
    std::cout << "Numbers in original form: ";
    std::ranges::copy(numbers, std::ostream_iterator<double>{ std::cout, " " });
    std::cout << '\n';

    // Multiply each number by PI using the function object.
    std::ranges::transform(numbers, numbers.begin(), setm::multiply_by_pi());

    // Print the result: numbers multiplied by PI.
    std::cout << "Numbers multiplied by PI: ";
    std::ranges::copy(numbers, std::ostream_iterator<double>{ std::cout, " " });
    std::cout << '\n';
}
