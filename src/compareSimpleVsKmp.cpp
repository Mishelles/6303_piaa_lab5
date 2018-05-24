#include <iostream>
#include <vector>
#include <random>
#include <string>

// "Наивный" алгоритм
unsigned int simpleSearch(const std::string&, const std::string&);

// КМП алгоритм
unsigned int kmpAlgorithm(const std::string&, const std::string&);

// Генерация случайной строки
std::string generateRandomString(const unsigned int& len = 100);

int main() {

    std::string text;
    std::string pattern;

    for (int i = 0; i < 10; i++) {
        text = generateRandomString();
        for (int j = 1; j < i; j++) {
            text += text;
        }

        pattern = text.substr(0, i + 10);

        std::cout << "****************************" << std::endl;
        std::cout << "Тест №" << i << std::endl;

        std::cout << "Случайная строка:" << std::endl;
        std::cout << text << std::endl;
        std::cout << "Длина строки: " << text.length() << std::endl;

        std::cout << "Шаблон:" << std::endl;
        std::cout << pattern << std::endl;
        std::cout << "Длина шаблона: " << pattern.length() << std::endl;
        std::cout << "Повторения шаблона: " << i + 1 << std::endl;

        std::cout << "--------------------------------" << std::endl;

        std::cout << "Наивный алгоритм: " << simpleSearch(pattern, text) << " операций." << std::endl;
        std::cout << "КМП алгоритм: " << kmpAlgorithm(pattern, text) << " операций." << std::endl;

        std::cout << "****************************" << std::endl;
        std::cout << std::endl;
    }

    return 0;
}

// "Наивный" алгоритм
unsigned int simpleSearch(const std::string& pattern, const std::string& text) {
    unsigned int counter = 0;

    const int textLength = text.length();
    const int patternLength = pattern.length();

    for (unsigned int i = 0; i < textLength; i++) {
        counter++;

        if (text[i] == pattern[0] && (textLength - 1 - i >= patternLength)) {
            counter++;

            for (unsigned j = 1; j < patternLength; j++) {
                if (text[i + j] == pattern[j]) counter++;
            }
        }
    }

    return counter;
}

// КМП алгоритм
unsigned int kmpAlgorithm(const std::string& pattern, const std::string& text) {
    unsigned int counter = 0;

    std::string concatString = pattern + '#' + text;
    int len = concatString.length();

    std::vector<int> indexes(len);

    for (unsigned int i = 1; i < len; i++) {
        unsigned int j = indexes[i - 1];

        while ((j > 0) && (concatString[i] != concatString[j])) {
            counter++;
            j = indexes[j - 1];
        }

        counter++;

        if (concatString[i] == concatString[j]) j++;

        indexes[i] = j;
    }

    return counter;
}

// Генерация случайной строки
std::string generateRandomString(const unsigned int& len) {
    std::string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    std::random_device rd;
    std::mt19937 engine(rd());

    std::uniform_int_distribution<> dist(0, alphabet.size() - 1);

    std::string generatedString = "";
    for(int i = 0; i < len; i++) {
        int randomIndex = dist(engine);
        generatedString += alphabet[randomIndex];
      }

    return generatedString;
}
