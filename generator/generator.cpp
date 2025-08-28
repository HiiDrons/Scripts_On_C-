#include <iostream>
#include <string>
#include <cstdlib>   // для rand() и srand()
#include <ctime>     // для time()

int main() {
    // Инициализация генератора случайных чисел
    std::srand(static_cast<unsigned int>(std::time(0)));

    char repeat;

    do {
        int length;
        std::cout << "Введите длину пароля: ";
        std::cin >> length;

        bool include_uppercase, include_lowercase, include_digits, include_symbols;

        std::cout << "Включать заглавные буквы? (y/n): ";
        char answer;
        std::cin >> answer;
        include_uppercase = (answer == 'y' || answer == 'Y');

        std::cout << "Включать строчные буквы? (y/n): ";
        std::cin >> answer;
        include_lowercase = (answer == 'y' || answer == 'Y');

        std::cout << "Включать цифры? (y/n): ";
        std::cin >> answer;
        include_digits = (answer == 'y' || answer == 'Y');

        std::cout << "Включать специальные символы? (y/n): ";
        std::cin >> answer;
        include_symbols = (answer == 'y' || answer == 'Y');

        // Проверка, выбран ли хотя бы один набор символов
        if (!include_uppercase && !include_lowercase && !include_digits && !include_symbols) {
            std::cout << "Ошибка: Вы не выбрали ни один тип символов. Пароль не может быть сгенерирован.\n";
            continue;
        }

        // Наборы символов
        const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
        const std::string digits    = "0123456789";
        const std::string symbols   = "!@#$%^&*()-_=+[]{}|;:,.<>?/";

        // Формируем строку из разрешённых символов
        std::string allowed_chars;
        if (include_uppercase) allowed_chars += uppercase;
        if (include_lowercase) allowed_chars += lowercase;
        if (include_digits)    allowed_chars += digits;
        if (include_symbols)   allowed_chars += symbols;

        // Генерация пароля
        std::string password;
        for (int i = 0; i < length; ++i) {
            int index = std::rand() % static_cast<int>(allowed_chars.size());
            password += allowed_chars[index];
        }

        std::cout << "Ваш новый пароль: " << password << std::endl;

        std::cout << "Сгенерировать ещё один? (y/n): ";
        std::cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    std::cout << "Спасибо за использование генератора паролей!" << std::endl;

    return 0;
}