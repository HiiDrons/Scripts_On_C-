#include <iostream>
#include <iomanip>

// Простая функция-задержка (без использования потоков)
void delay(int milliseconds) {
    const auto start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < milliseconds);
}

int main() {
    int size;

    std::cout << "Введите размер таблицы: ";
    std::cin >> size;

    // Заголовок с номерами столбцов
    std::cout << "\033[1;32m";  // зелёный цвет
    std::cout << "     |";
    for (int col = 1; col <= size; ++col) {
        std::cout << std::setw(4) << col;
    }
    std::cout << "\n";

    // Разделительная линия
    std::cout << "-----+";
    for (int col = 1; col <= size; ++col) {
        std::cout << "----";
    }
    std::cout << "\n\033[0m";  // сброс цвета

    // Вывод самой таблицы с анимацией
    for (int row = 1; row <= size; ++row) {
        std::cout << "\033[1;34m" << std::setw(4) << row << "\033[0m|";

        for (int col = 1; col <= size; ++col) {
            if (row == col)
                std::cout << "\033[1;31m";  // красим диагональ в красный

            std::cout << std::setw(4) << row * col;

            std::cout << "\033[0m";  // сброс цвета
        }

        std::cout << std::endl;
        delay(200);  // пауза в 200 миллисекунд
    }

    return 0;
}