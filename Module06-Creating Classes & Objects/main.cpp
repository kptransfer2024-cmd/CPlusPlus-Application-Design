#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string bookName;
    int bookId;
    double price;
    int pages;

public:
    Book(string bookTitle, int bookNumber, double bookCost, int bookPages) {
        bookName = bookTitle;
        bookId = bookNumber;
        price = bookCost;
        pages = bookPages;
    }

    void displayBookInfo() {
        cout << "Book Name: " << bookName << endl;
        cout << "Book ID: " << bookId << endl;
        cout << "Price: $" << price << endl;
        cout << "Pages: " << pages << endl;
    }

    void applyDiscount(double discount) { 
        price = price - (price * discount / 100);
        cout << discount << "% off applied!" << endl;
    }


    string getName() {
        return bookName;
    }

    int getBookId() {
        return bookId;
    }
    
    double getPrice() {
        return price;
    }

    int getPages() {
        return pages;
    }

    void setBookId(int newId) {
        bookId = newId;
        cout << "Updated Book ID: " << bookId << endl;
    }

    void setPrice(double newPrice) {
        price = newPrice;
        cout << "Updated Book price: " << newPrice << endl;
    }
};

int main() {
    Book book1("The Great Gatsby", 101, 12.99, 451);
    Book book2("To Kill a Mockingbird", 102, 14.99, 366);
    Book book3("Little Women", 103, 18.99, 269);
    Book book4("Introduction to Linear Algebra", 104, 11.99, 498);
    Book book5("C++ Primer Plus (6th Edition) (Developer's Library) 6th Edition(not required) ", 105, 20.99, 800);

    book1.displayBookInfo();
    cout << endl;
    book2.displayBookInfo();
    cout << endl;
    book3.displayBookInfo();
    cout << endl;
    book4.displayBookInfo();
    cout << endl;
    book5.displayBookInfo();

    book1.setPrice(13.99);
    cout << "New Price: $" << book1.getPrice() << endl;

    book2.setBookId(108);
    cout << "New Book ID: " << book2.getBookId() << endl;

    book3.applyDiscount(40);
    cout << "New Price: $" << book3.getPrice() << endl;

    return 0;
}