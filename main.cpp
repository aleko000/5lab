#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <Windows.h>
#include "book.h"
#include "library.h"

const char* menu =
"\n"
"1. Поиск книги по названию\n"
"2. Поиск книги по дате издания\n"
"3. Поиск книги по автору\n"
"4. Добавление книги в библиотеку\n"
"5. Удаление книги из библиотеки\n"
"6. Список всех книг\n"
"0. Выход\n\n"
"Ваш выбор: ";

int main(int argc, const char* argv[]) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Library lib;

    lib.append(Book(1835, "Пушкин", "Золотая рыбка"));
    lib.append(Book(1842, "Гоголь", "Мертвые души"));
    lib.append(Book(1824, "Грибоедов", "Горе от ума"));
    lib.append(Book(1935, "Достоевский", "Преступление и наказание"));
    lib.append(Book(1935, "Сталин", "Горе от ума"));

    int choice;
    std::string what;
    int year;
    Book book;
    Library::Bookcase::iterator it;

    do {
        std::cout << menu;
        std::cin >> choice;
        std::cin.ignore();
        std::cout << std::endl;

        switch (choice) {
        case 1:
            std::cout << "Укажите название книги: ";
            getline(std::cin, what);
            it = lib.begin();
            do {
                it = lib.findByTitle(what, it);
                if (it != lib.end()) {
                    std::cout << *it;
                    std::cout << std::endl;
                    ++it;
                }
            } while (it != lib.end());
            break;
        case 2:
            std::cout << "Укажите год издания книги: ";
            std::cin >> year;
            std::cin.ignore();
            it = lib.begin();
            do {
                it = lib.findByYear(year, it);
                if (it != lib.end()) {
                    std::cout << *it;
                    std::cout << std::endl;
                    ++it;
                }
            } while (it != lib.end());
            break;
        case 3:
            std::cout << "Укажите автора книги: ";
            getline(std::cin, what);
            it = lib.begin();
            do {
                it = lib.findByAuthor(what, it);
                if (it != lib.end()) {
                    std::cout << *it;
                    std::cout << std::endl;
                    ++it;
                }
            } while (it != lib.end());
            break;
        case 4:
            inputBook(book);
            lib.append(book);
            break;
        case 5:
            inputBook(book);
            if (lib.remove(book))
                std::cout << "книга удалена\n";
            else
                std::cout << "книга не найдена\n";
            break;
        case 6:
            it = lib.begin();
            do {
                if (it != lib.end()) {
                    std::cout << *it;
                    std::cout << std::endl;
                }
                it = lib.nextBook(it);
            } while (it != lib.end());
            break;
        case 0:
            break;
        default:
            std::cout << "\nНе попал ((\n\n";
        }
    } while (choice != 0);

    return 0;
}
