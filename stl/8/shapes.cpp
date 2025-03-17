/*
    Гапонов Дмитрий 
    группа 5130904_30022
    Задание:
        Разработать программу, которая:
            a. Реализует иерархию геометрических фигур состоящую из:
                i. Класс Shape. 
                    1. Содержит информацию о положении центра фигуры (координаты x и y).
                    2. Содердит метод IsMoreLeft, позволяющий определить расположена ли 
                        данная фигура левее (определяется по положению центра) чем фигура переданная в качестве аргумента
                    3. Содердит метод IsUpper, позволяющий определить расположена ли данная фигура выше 
                        (определяется по положению центра) чем фигура переданная в качестве аргумента
                    4. Определяет чисто виртаульную функцию рисования Draw 
                        (каждая фигура в реализации этой функци должна выводить на стандартный вывод свое название и положение цента)
                ii. Класс Circle производный от класса Shape
                    1. Реализует Draw
                iii. Класс Triangle производный от класса Shape
                    1. Реализует Draw
                iv. Класс Square производный от класса Shape
                    1. Реализует Draw
            b. Содержит список list<Shape*>, заполенный указателями на различные фигуры
            c. С помощью стандартных алгоритмов и адаптеров выводит (Draw) все фигуры
            d. С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра слева-направо 
                (имется в виду, что в начале списка должны идти фигуры находящиеся левее, координата x ) и выводит фигуры (Draw)
            e. С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра справа-налево и выводит фигуры
            f. С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра сверху-вниз и выводит фигуры
            g. С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра снизу-вверх и выводит фигуры
*/

#include <algorithm>
#include <iostream>
#include <list>
#include <memory>
#include <random>
#include <string_view>
#include <utility>

namespace setm {

enum class shape_type : uint8_t {
    CIRCLE,
    TRIANGLE,
    SQUARE,
    _COUNT  // Для указания количества фигур.
};

class shape {
public:
    shape(double x, double y) noexcept
        : x{ x }, y{ y } {}

    virtual ~shape() noexcept = default;

    virtual void draw() const noexcept = 0;

    [[nodiscard]] bool is_more_left(const shape& other) const noexcept {
        return x < other.x;
    }

    [[nodiscard]] bool is_upper(const shape& other) const noexcept {
        return y > other.y;
    }

protected:
    const double x;
    const double y;
};

class circle : public shape {
public:
    using shape::shape;

    void draw() const noexcept override {
        std::cout << "Круг в точке (" << x << ", " << y << ")\n";
    }
};

class triangle : public shape {
public:
    using shape::shape;

    void draw() const noexcept override {
        std::cout << "Треугольник в точке (" << x << ", " << y << ")\n";
    }
};

class square : public shape {
public:
    using shape::shape;

    void draw() const noexcept override {
        std::cout << "Квадрат в точке (" << x << ", " << y << ")\n";
    }
};

template<typename Container>
void draw_shapes(const Container& shapes, std::string_view message = "") {
    std::cout << message;
    for(const auto& shape : shapes)
        shape->draw();
    std::cout << '\n';
}

// Генерация случайного числа в заданном диапазоне.
static double generate_random_double(double min, double max) noexcept {
    static std::default_random_engine gen{ std::random_device{}() };
    static std::uniform_real_distribution dist{ min, max };

    return dist(gen);
}

// Генерация случайного типа фигуры.
static setm::shape_type generate_random_shape_type() noexcept {
    static std::default_random_engine gen{ std::random_device{}() };
    static std::uniform_int_distribution dist{ 0, static_cast<int>(setm::shape_type::_COUNT) - 1 };

    return static_cast<setm::shape_type>(dist(gen));
}

// Генерация случайной фигуры.
shape* generate_random_shape() {
    const auto x{ generate_random_double(-100.0, 100.0) };
    const auto y{ generate_random_double(-100.0, 100.0) };
    const auto type{ generate_random_shape_type() };

    switch(type) {
        case shape_type::CIRCLE:
            return new circle{ x, y };
        case shape_type::TRIANGLE:
            return new triangle{ x, y };
        case shape_type::SQUARE:
            return new square{ x, y };
        default:
            // Если достигнут недостижимый код, выбрасываем исключение.
            throw std::runtime_error("Неизвестный тип фигуры");
    }
}

}  // namespace setm

int main() {
    std::list<setm::shape*> shapes(10);
    std::generate(std::begin(shapes), std::end(shapes), [] { return setm::generate_random_shape(); });

    // Отображение всех фигур.
    std::cout << "Все " << shapes.size() << " фигур:\n";
    setm::draw_shapes(shapes);

    // Сортировка и отображение фигур.
    shapes.sort([](const auto& a, const auto& b) { return a->is_more_left(*b); });
    std::cout << "Слева направо:\n";
    setm::draw_shapes(shapes);
    shapes.sort([](const auto& a, const auto& b) { return b->is_more_left(*a); });
    std::cout << "Справа налево:\n";
    setm::draw_shapes(shapes);
    shapes.sort([](const auto& a, const auto& b) { return a->is_upper(*b); });
    std::cout << "Сверху вниз:\n";
    setm::draw_shapes(shapes);
    shapes.sort([](const auto& a, const auto& b) { return b->is_upper(*a); });
    std::cout << "Снизу вверх:\n";
    setm::draw_shapes(shapes);

    // Очистка памяти.
    for(auto shape : shapes)
        delete shape;
}