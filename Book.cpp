#include "book.h"
#include <iostream>

Book::Book() : m_year(0) {}

Book::Book(int year, const std::string& author, const std::string& title) : m_year(0) {
    set(year, author, title);
}

void Book::set(int year, const std::string& author, const std::string& title) {
    m_year = year;
    m_author = author;
    m_title = title;
}

int Book::getYear() const { return m_year; }
std::string Book::getAuthor() const { return m_author; }
std::string Book::getTitle() const { return m_title; }

bool Book::operator == (const Book& op) {
    return m_year == op.m_year &&
        m_author == op.m_author &&
        m_title == op.m_title;
}

std::ostream& operator << (std::ostream& os, const Book& b) {
    return os
        << b.m_author << std::endl
        << b.m_title << std::endl
        << b.m_year << std::endl;
}

void inputBook(Book& b) {
    std::string au, ti;
    int yr;
    std::cout << "Ввод данных о книге\n" << "~~~~~~~~~~~~~~~~~~~\n";
    std::cout << "Автор      : ";
    getline(std::cin, au);
    std::cout << "Название   : ";
    getline(std::cin, ti);
    std::cout << "Год издания: ";
    std::cin >> yr;
    std::cin.ignore();
    b.set(yr, au, ti);
}
