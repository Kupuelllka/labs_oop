/*
    Гапонов Дмитрий 
    группа 5130904_30022
    Задание:
        Написать программу, которая выполняет следующие действия:
            a. Заполняет вектор геометрическими фигурами. Геометрическая фигура может быть треугольником, квадратом, прямоугольником или пяти угольником. Структура описывающая геометрическую фигуру  определена ниже, 
            b. Подсчитывает общее количество вершин всех фигур содержащихся в векторе (так треугольник добавляет к общему числу 3, квадрат 4 и т.д.)
            c. Подсчитывает количество треугольников, квадратов и прямоугольников в векторе
            d. Удаляет все пятиугольники 
            e. На основании этого вектора создает vector<Point>, который содержит координаты одной из вершин (любой) каждой фигуры, т.е. первый элемент этого вектора содержит координаты одной из вершину первой фигуры, второй элемент этого вектора содержит координаты одной из вершину второй фигуры и т.д.
            f. Изменяет вектор так, чтобы он содержал в начале все треугольники, потом все квадраты, а потом прямоугольники.
            g. Распечатывает вектор после каждого этапа работы
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

namespace setm {

struct point {
    int x;
    int y;
};

struct shape {
    int vertex_num;  // Количество вершин.
    std::vector<point> vertexes;  // Вектор вершин.
};

std::ostream& operator<<(std::ostream& out, const shape& s) {
    out << "{ Номер вершины: " << s.vertex_num << ", вершины: [ ";
    for(const auto& vertex : s.vertexes)
        out << "(" << vertex.x << ", " << vertex.y << ") ";

    return out << "] }";
}

void generate_random_shapes(std::vector<shape>& shapes, std::size_t count) {
    static std::default_random_engine gen{ std::random_device{}() };
    static std::uniform_int_distribution dist_vertex_num{ 3, 5 };
    static std::uniform_int_distribution dist_coordinate{ -100, 100 };

    std::generate_n(std::back_inserter(shapes), count, [] {
        const auto vertices_count{ dist_vertex_num(gen) };
        std::vector<point> vertices(vertices_count);

        for(auto& vertex : vertices) {
            vertex.x = dist_coordinate(gen);
            vertex.y = dist_coordinate(gen);
        }

        return shape{ vertices_count, vertices };
    });
}

[[nodiscard]] inline int total_vertices(const std::vector<shape>& shapes) {
    return std::accumulate(std::begin(shapes), std::end(shapes), 0,
                           [](int acc, const shape& s) {
                               return acc + s.vertex_num;
                           });
}

enum class shape_type : uint8_t {
    TRIANGLE = 3,   // Треугольник.
    RECTANGLE = 4,  // Прямоугольник.
    PENTAGON = 5,   // Пятиугольник.
    SQUARE = 14     // Квадрат (специальный случай, не связанный с количеством сторон).
};

[[nodiscard]] inline bool is_square(const shape& s) {
    if(s.vertex_num != 4) return false;

    // Вычисляем длины всех сторон.
    const auto side1{ std::sqrt(std::pow(s.vertexes[0].x - s.vertexes[1].x, 2) + std::pow(s.vertexes[0].y - s.vertexes[1].y, 2)) };
    const auto side2{ std::sqrt(std::pow(s.vertexes[1].x - s.vertexes[2].x, 2) + std::pow(s.vertexes[1].y - s.vertexes[2].y, 2)) };
    const auto side3{ std::sqrt(std::pow(s.vertexes[2].x - s.vertexes[3].x, 2) + std::pow(s.vertexes[2].y - s.vertexes[3].y, 2)) };
    const auto side4{ std::sqrt(std::pow(s.vertexes[3].x - s.vertexes[0].x, 2) + std::pow(s.vertexes[3].y - s.vertexes[0].y, 2)) };

    // Проверяем, все ли стороны равны.
    return side1 == side2 && side2 == side3 && side3 == side4;
}

[[nodiscard]] inline std::size_t count_shapes(const std::vector<shape>& shapes, shape_type type) {
    // Если запрашивается квадрат, проверяем, все ли стороны равны.
    if(type == shape_type::SQUARE)
        return std::count_if(std::begin(shapes), std::end(shapes), [](const shape& s) {
            return s.vertex_num == 4 && is_square(s);
        });

    return std::count_if(std::begin(shapes), std::end(shapes), [type](const shape& s) {
        return s.vertex_num == static_cast<int>(type);
    });
}

void remove_shapes(std::vector<shape>& shapes, shape_type type) {
    shapes.erase(std::remove_if(std::begin(shapes), std::end(shapes), [type](const shape& s) {
                     if(type == shape_type::SQUARE || type == shape_type::RECTANGLE) {
                         return s.vertex_num == static_cast<int>(type) && is_square(s);
                     }
                     return s.vertex_num == static_cast<int>(type);
                 }),
                 std::end(shapes));
}

std::vector<setm::point> extract_vertices(const std::vector<setm::shape>& shapes) {
    std::vector<setm::point> vertices;
    std::transform(std::begin(shapes), std::end(shapes), std::back_inserter(vertices),
                   [](const setm::shape& s) { return s.vertexes[0]; });

    return vertices;
}

void reorder_shapes(std::vector<setm::shape>& shapes) {
    // Предикат для проверки, является ли фигура треугольником.
    auto is_triangle{ [](const setm::shape& s) {
        return s.vertex_num == static_cast<int>(setm::shape_type::TRIANGLE);
    } };
    // Предикат для проверки, является ли фигура прямоугольником (но не квадратом).
    auto is_rectangle{ [](const setm::shape& s) {
        return s.vertex_num == static_cast<int>(setm::shape_type::RECTANGLE) && !is_square(s);
    } };
    // Предикат для проверки, является ли фигура пятиугольником.
    auto is_pentagon{ [](const setm::shape& s) {
        return s.vertex_num == static_cast<int>(setm::shape_type::PENTAGON);
    } };

    // Переупорядочиваем вектор так, чтобы треугольники шли первыми, затем квадраты,
    // затем прямоугольники и, наконец, пятиугольники.
    auto triangle_end{ std::stable_partition(std::begin(shapes), std::end(shapes), is_triangle) };
    auto square_end{ std::stable_partition(triangle_end, std::end(shapes), is_square) };
    auto rectangle_end{ std::stable_partition(square_end, std::end(shapes), is_rectangle) };
    std::stable_partition(rectangle_end, std::end(shapes), is_pentagon);
}

}  // namespace setm

int main() {
    // 1. Генерация 20 случайных фигур.
    std::vector<setm::shape> shapes;
    setm::generate_random_shapes(shapes, 5);
    std::cout << "1. Сгенерировано " << shapes.size() << " случайных фигур:\n";
    for(const auto& shape : shapes)
        std::cout << shape << '\n';

    // 2. Добавляем 5 квадратов для тестов.
    shapes.emplace_back(setm::shape{ 4, { { 0, 0 }, { 1, 0 }, { 1, 1 }, { 0, 1 } } });
    shapes.emplace_back(setm::shape{ 4, { { 2, 2 }, { 4, 2 }, { 4, 4 }, { 2, 4 } } });
    shapes.emplace_back(setm::shape{ 4, { { 5, 5 }, { 7, 5 }, { 7, 7 }, { 5, 7 } } });
    shapes.emplace_back(setm::shape{ 4, { { 8, 8 }, { 10, 8 }, { 10, 10 }, { 8, 10 } } });
    shapes.emplace_back(setm::shape{ 4, { { 11, 11 }, { 13, 11 }, { 13, 13 }, { 11, 13 } } });
    std::cout << "\n2. Добавлено 5 квадратов для тестов. Теперь всего фигур: " << shapes.size() << ":\n";
    for(const auto& shape : shapes)
        std::cout << shape << '\n';

    // 3. Подсчет общего количества вершин.
    std::cout << "\n3. Общее количество вершин: " << setm::total_vertices(shapes) << '\n';

    // 4. Подсчет количества фигур каждого типа.
    std::cout << "\n4. Количество фигур каждого типа:\n";
    std::cout << "\tТреугольники: " << setm::count_shapes(shapes, setm::shape_type::TRIANGLE) << '\n';
    std::cout << "\tКвадраты: " << setm::count_shapes(shapes, setm::shape_type::SQUARE) << '\n';
    std::cout << "\tПрямоугольники: " << setm::count_shapes(shapes, setm::shape_type::RECTANGLE) << '\n';
    std::cout << "\tПятиугольники: " << setm::count_shapes(shapes, setm::shape_type::PENTAGON) << '\n';

    // 5. Удаление всех пятиугольников.
    setm::remove_shapes(shapes, setm::shape_type::PENTAGON);
    std::cout << "\n5. После удаления пятиугольников осталось " << shapes.size() << " фигур:\n";
    for(const auto& shape : shapes)
        std::cout << shape << '\n';

    // 6. Извлечение вершин из фигур.
    const auto extracted_vertices{ setm::extract_vertices(shapes) };
    std::cout << "\n6. Первые вершины, извлеченные из фигур:\n";
    for(const auto& vertex : extracted_vertices)
        std::cout << "Вершина: (" << vertex.x << ", " << vertex.y << ")\n";

    // 7. Переупорядочивание фигур: треугольники, квадраты, прямоугольники, пятиугольники.
    setm::reorder_shapes(shapes);
    std::cout << "\n7. Переупорядоченные фигуры:\n";
    for(const auto& shape : shapes)
        std::cout << shape << '\n';
}