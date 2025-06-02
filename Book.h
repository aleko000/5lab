#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
public:
    Book();
    Book(int year, const std::string& author, const std::string& title);
    void set(int year, const std::string& author, const std::string& title);
    int getYear() const;
    std::string getAuthor() const;
    std::string getTitle() const;
    bool operator == (const Book& op);
    friend std::ostream& operator << (std::ostream& os, const Book& b);

private:
    int m_year;
    std::string m_author, m_title;
};

void inputBook(Book& b);

#endif
