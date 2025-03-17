/*
    Гапонов Дмитрий 
    группа 5130904_30022
    Задание:
        Разработать функтор, позволяющий собирать статистику о последовательности целых чисел (послед может содержать числа от -500 до 500). Функтор после обработки последовательности алгоритмом for_each должен предоставлять следующую статистику:
            a. Максимальное число в последовательности
            b. Минимальное число в последовательности
            c. Среднее число в последовательности
            d. Количество положительных чисел
            e. Количество отрицательных чисел
            f. Сумму нечетных элементов последовательности
            g. Сумму четных элементов последовательности
            h. Совпадают ли первый и последний элементы последовательности.
*/

#include <algorithm>
#include <iostream>
#include <limits>
#include <random>
#include <ranges>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>

namespace setm {

class statistics {
public:
    // Оператор-функтор для обработки каждого элемента в последовательности.
    void operator()(int value) {
        // Обновление максимальных и минимальных значений.
        max = std::max(max, value);
        min = std::min(min, value);

        // Обновление счетчиков положительных и отрицательных чисел.
        if(value > 0)
            positives++;
        else if(value < 0)
            negatives++;

        // Обновление суммы нечетных и четных чисел.
        if(value % 2)
            odd_sum += value;
        else
            even_sum += value;

        // Если это первый элемент, обновляем переменную `first`.
        if(count == 0)
            first = value;

        // Всегда обновляем переменную `last` и увеличиваем `count`.
        last = value;
        ++count;
    }

    std::string printStatistics() const {
        if(count == 0)
            return "Пустая последовательность";

        std::ostringstream oss;
        oss << "Количество элементов: " << count << "\n"
            << "Максимальное число: " << max << "\n"
            << "Минимальное число: " << min << "\n"
            << "Среднее: " << (static_cast<double>(odd_sum) / count + static_cast<double>(even_sum) / count) << "\n"
            << "Положительные числа: " << positives << "\n"
            << "Отрицательные числа: " << negatives << "\n"
            << "Сумма нечетных чисел: " << odd_sum << "\n"
            << "Сумма четных чисел: " << even_sum << "\n"
            << "Первый и последний элемент совпадают: " << (first == last ? "Да" : "Нет");
        return oss.str();
    }

private:
    int max{ std::numeric_limits<int>::min() };
    int min{ std::numeric_limits<int>::max() };
    std::size_t positives{};
    std::size_t negatives{};
    int odd_sum{};
    int even_sum{};
    std::size_t count{};
    int first{};
    int last{};
};

}  // namespace setm
int main() {
    // Генерация 30 случайных чисел в диапазоне [-500, 500].
    static constexpr auto sequence_size{ 30 };
    static constexpr auto min_value{ -500 };
    static constexpr auto max_value{ 500 };
    std::vector<int> sequence(sequence_size);
    std::ranges::generate(sequence, [] {
        static std::default_random_engine gen{ std::random_device{}() };
        static std::uniform_int_distribution dist{ min_value, max_value };

        return dist(gen);
    });

    // Вывод последовательности.
    std::cout << "Сгенерированная последовательность: { ";
    std::ranges::copy(sequence, std::ostream_iterator<int>{ std::cout, " " });
    std::cout << " }\n";

    // Обработка каждого элемента в последовательности и получение статистики.
    setm::statistics stats;
    std::ranges::for_each(sequence, [&stats](auto value) { stats(value); });

    // Вывод статистики.
    std::cout << "Статистика:\n"
              << stats.printStatistics() << '\n';
}