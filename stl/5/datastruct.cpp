/*
    Гапонов Дмитрий 
    группа 5130904_30022
    Задание:
        Написать программа, которая выполняет следующие действия:
            a. Заполняет vector<DataStruct> структурами DataStruct, при этом key1 и key2, генерируются случайным образом в диапазоне от -5 до 5, str заполняется из таблицы (таблица содержит 10 произвольных строк, индекс строки генерируется случайным образом)
            b. Выводит полученный вектор на печать
            c. Сортирует вектор следующим образом:
                i. По возрастанию key1
                ii. Если key1 одинаковые, то по возрастанию key2
                iii. Если key1 и key2 одинаковые, то по возрастанию длинны строки str
            d. Выводит полученный вектор на печать  
*/
#include <algorithm>
#include <array>
#include <iostream>
#include <random>
#include <string>
#include <vector>

namespace setm {

// Структура данных, содержащая два ключа и строку.
struct DataStruct {
    int key1;       // Первый ключ.
    int key2;       // Второй ключ.
    std::string str; // Строка.

    // Метод для сортировки вектора структур.
    static void sort(std::vector<DataStruct>& datastructs) {
        std::sort(datastructs.begin(), datastructs.end(), [](const auto& a, const auto& b) {
            if(a.key1 != b.key1)
                return a.key1 < b.key1;
            else if(a.key2 != b.key2)
                return a.key2 < b.key2;
            else
                return a.str.size() < b.str.size();
        });
    }

    // Перегрузка оператора вывода для структуры DataStruct.
    friend std::ostream& operator<<(std::ostream& os, const DataStruct& datastruct) {
        os << "ds: [ key1: " << datastruct.key1
           << ",\tkey2: " << datastruct.key2
           << ",\tstr: \"" << datastruct.str << "\" ]";
        return os;
    }

    // Генерация случайного ключа в диапазоне от -5 до 5.
    static int generate_key() {
        static std::default_random_engine gen{ std::random_device{}() };
        static std::uniform_int_distribution dist{ -5, 5 };

        return dist(gen);
    }

    // Генерация случайной строки из предопределенного набора.
    static std::string generate_string() {
        static constexpr std::array strings{
            "Lorem ipsum", "dolor sit amet", "consectetur adipiscing",
            "elit", "sed do eiusmod", "tempor incididunt", "ut labore et",
            "dolore magna aliqua", "Ut enim ad", "minim veniam"
        };
        static std::default_random_engine gen{ std::random_device{}() };
        static std::uniform_int_distribution dist{ 0, static_cast<int>(strings.size() - 1) };

        return strings[dist(gen)];
    }

    // Заполнение вектора случайными структурами DataStruct.
    static void fill_random(std::vector<DataStruct>& datastructs, std::size_t count) {
        std::generate_n(std::back_inserter(datastructs), count, [] {
            return DataStruct{ generate_key(), generate_key(), generate_string() };
        });
    }

    // Генерация тестовых данных.
    static std::vector<DataStruct> generate_test_data() {
        return {
            {3, -2, "dolor sit amet"},      // Разные key1.
            {-1, 0, "elit"},                // Разные key1.
            {2, 2, "tempor incididunt"},    // Разные key1.
            {-3, 4, "Ut enim ad"},          // Разные key1.
            {1, -5, "minim veniam"},        // Разные key1.
            {0, 3, "consectetur adipiscing"}, // Разные key1.
            {-4, 1, "sed do eiusmod"},      // Разные key1.
            {5, -3, "Lorem ipsum"},         // Разные key1.
            {-2, 2, "tempor incididunt"},   // Одинаковые key1, разные key2.
            {2, 3, "tempor incididunt"},    // Одинаковые key1, разные key2.
            {2, 2, "short string"},         // Одинаковые key1 и key2, разная длина строки.
            {2, 2, "longer string"},       // Одинаковые key1 и key2, разная длина строки.
            {2, 2, "medium string"},       // Одинаковые key1 и key2, разная длина строки.
            {2, 2, "medium string"}        // Одинаковые key1, key2 и длина строки.
        };
    }
};

}  // namespace setm

int main() {
    std::vector<setm::DataStruct> datastructs;

    // Добавляем тестовые данные.
    auto test_data{ setm::DataStruct::generate_test_data() };
    datastructs.insert(datastructs.end(), test_data.begin(), test_data.end());

    // Генерируем дополнительные случайные данные.
    setm::DataStruct::fill_random(datastructs, 5);

    // Вывод данных до сортировки.
    std::cout << "До сортировки:\n";
    for(const auto& datastruct : datastructs)
        std::cout << datastruct << '\n';

    // Сортировка методом класса.
    setm::DataStruct::sort(datastructs);

    // Вывод данных после сортировки.
    std::cout << "\nПосле сортировки:\n";
    for(const auto& datastruct : datastructs)
        std::cout << datastruct << '\n';
}