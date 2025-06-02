#include "library.h"
#include <algorithm>

Library::Library() {}

void Library::append(const Book& book) {
    m_bc.push_back(book);
}

bool Library::remove(const Book& book) {
    auto it = std::find(m_bc.begin(), m_bc.end(), book);
    if (it != m_bc.end()) {
        m_bc.erase(it);
        return true;
    }
    return false;
}

Library::Bookcase::iterator Library::findByTitle(const std::string& title, Bookcase::iterator from) {
    return std::find_if(from, m_bc.end(), [title](const Book& b) { return title == b.getTitle(); });
}

Library::Bookcase::iterator Library::findByAuthor(const std::string& author, Bookcase::iterator from) {
    return std::find_if(from, m_bc.end(), [author](const Book& b) { return author == b.getAuthor(); });
}

Library::Bookcase::iterator Library::findByYear(int year, Bookcase::iterator from) {
    return std::find_if(from, m_bc.end(), [year](const Book& b) { return year == b.getYear(); });
}

Library::Bookcase::iterator Library::nextBook(Bookcase::iterator from) {
    return ++from;
}

Library::Bookcase::iterator Library::begin() { return m_bc.begin(); }
Library::Bookcase::iterator Library::end() { return m_
