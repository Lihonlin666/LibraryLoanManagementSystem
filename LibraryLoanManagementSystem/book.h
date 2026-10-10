#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <iostream>

class Book
{
private:
    std::string bookName;
    std::string isbn;
    std::string press;
    double price;
    int page;
    bool isAvailable;
public:
    Book();
    Book(const std::string& name, const std::string& isbn_, const std::string& press_, double price_, int page_, bool avail = true);

    std::string getBookName() const;
    std::string getIsbn() const;
    std::string getPress() const;
    double getPrice() const;
    int getPage() const;
    bool getAvailable() const;

    void setBookName(const std::string& n);
    void setIsbn(const std::string& id);
    void setPress(const std::string& p);
    void setPrice(double pr);
    void setPage(int pg);
    void setAvailable(bool sta);

    bool checkIsbnValid() const;
    void showInfo() const;
};
#endif
