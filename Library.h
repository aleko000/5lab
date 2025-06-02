#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include <vector>

class Library {
public:
    typedef std::vector<Book> Bookcase;

    Library();
    void append(const Book& book);
    bool remove(const Book& book);
    Bookcase::iterator findByTitle(const std::string& title, Bookcase::iterator from);
    Bookcase::iterator findByAuthor(const std::string& author, Bookcase::iterator from);
    Bookcase::iterator findByYear(int year, Bookcase::iterator from);
    Bookcase::iterator nextBook(Bookcase::iterator from);
    Bookcase::iterator begin();
    Bookcase::iterator end();

private:
    Bookcase m_bc;
};

#endif
