/*
    Гапонов Дмитрий 
    группа 5130904_30022
    Задание:
    Написать программу, которая выполняет следующие действия (все операции должны выполняться с помощью стандартных алгоритмов):
        a. Читает содержимое текстового файла
        b. Выделяет слова, словом считаются последовательность символов разделенных пробелами и/или знаками табуляции и/или символами новой строки
        c. Вывести список слов присутствующий в тексте без повторений (имеется в виду, что одно и то же слово может присутствовать в списке только один раз)
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ranges>
#include <sstream>
#include <string>
#include <unordered_set>

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cerr << "Использование: " << argv[0] << " <input_file>\n";
        return EXIT_FAILURE;
    }

    std::ifstream file{ argv[1] };
    if(!file) {
        std::cerr << "Не удалось открыть файл.\n";
        return EXIT_FAILURE;
    }

    // Читаем всё содержимое файла в строку эффективно с использованием потоковых итераторов.
    std::string text{ std::istreambuf_iterator<char>{ file }, {} };

    // Закрываем файл явно после чтения его содержимого.
    // Это не обязательно, так как деструктор ifstream
    // автоматически закроет файл, но это хорошая практика.
    file.close();

    // Преобразуем все буквенные символы в строке в нижний регистр,
    // заменяя небуквенные символы на пробелы.
    std::transform(text.begin(), text.end(), text.begin(), [](char c) {
        return std::isalpha(c) ? std::tolower(c) : ' ';
    });

    // Используем stringstream для разбиения преобразованного текста на токены
    // и сохраняем уникальные слова в unordered_set.
    std::stringstream ss{ text };
    std::unordered_set<std::string> unique_words{ std::istream_iterator<std::string>{ ss },
                                                  std::istream_iterator<std::string>{} };

    // Выводим уникальные слова.
    for(const auto& word : unique_words)
        std::cout << word << '\n';

    // Выводим общее количество найденных уникальных слов.
    std::cout << "Найдено " << unique_words.size() << " уникальных слов.\n";
}
