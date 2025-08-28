#include <iostream>
#include <iomanip>

int main() {
    int size;

    std::cout << "Введите размер таблицы:";
    std::cin >> size;

    std::cout << "\033[1;32m";
    std::cout << "     |";
    for (int col = 1; col <= size; ++col) {
        std::cout << std::setw(4) << col;
    }
    std::cout << "\n";

    std::cout << "-----+";
    for (int col = 1; col <= size; ++col) {
        std::cout << "----";
    }
    std::cout << "\n\033[0m"; 

    for (int row = 1; row <= size; ++row) {
        std::cout << "\033[1;34m" << std::setw(4) << row << "\033[0m|";

        for(int col = 1; col <= size; ++col) {
            if(row == col)
                std::cout << "\033[1;31m";

            std::cout << std::setw(4) << row * col;

            std::cout << "\033[0m"; 
        }

        std::cout << std::endl;
    }

    return 0;
}






 
