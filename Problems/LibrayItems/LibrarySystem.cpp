#include <iostream>
#include <vector>
using namespace std;

// Abstract base class for library items
class LibraryItem {
public:
    virtual string getTitle() const = 0;
    virtual string getUID() const = 0;
    virtual string getProperty() const = 0;
    virtual int getCost() const = 0;
    virtual int getLateFee(int days) const = 0;
    virtual ~LibraryItem() = default;
};

// Concrete class for Book
class Book : public LibraryItem {
private:
    string title;
    string uid;
    string author;
    int cost;
public:
    Book(string title, string uid, string author, int cost) 
        : title(title), uid(uid), author(author), cost(cost) {}

    string getTitle() const override { return title; }
    string getUID() const override { return uid; }
    string getProperty() const override { return author; }
    int getCost() const override { return cost; }
    int getLateFee(int days) const override { return days * 100; }
};

// Concrete class for CD
class CD : public LibraryItem {
private:
    string title;
    string uid;
    string publisher;
    int cost;
public:
    CD(string title, string uid, string publisher, int cost) 
        : title(title), uid(uid), publisher(publisher), cost(cost) {}

    string getTitle() const override { return title; }
    string getUID() const override { return uid; }
    string getProperty() const override { return publisher; }
    int getCost() const override { return cost; }
    int getLateFee(int days) const override { return days * 50; }
};

// Concrete class for DVD
class DVD : public LibraryItem {
private:
    string title;
    string uid;
    string publisher;
    int cost;
public:
    DVD(string title, string uid, string publisher, int cost) 
        : title(title), uid(uid), publisher(publisher), cost(cost) {}

    string getTitle() const override { return title; }
    string getUID() const override { return uid; }
    string getProperty() const override { return publisher; }
    int getCost() const override { return cost; }
    int getLateFee(int days) const override { return days * 150; }
};

// Service class for handling library item operations
class LibraryService {
public:
    static int calculateTotalFees(const vector<LibraryItem*>& items) {
        int totalFees = 0;
        for (const auto& item : items) {
            totalFees += item->getCost();
        }
        return totalFees;
    }

    static int calculateLateFees(const vector<LibraryItem*>& items, int days) {
        int lateFees = 0;
        for (const auto& item : items) {
            lateFees += item->getLateFee(days);
        }
        return lateFees;
    }

    static void checkOutItems(const vector<LibraryItem*>& items) {
        cout << "-------------------- Items Rented --------------------" << endl;
        cout << "UID\tTitle\tOwner\t\tCost" << endl;
        for (const auto& item : items) {
            cout << item->getUID() << "\t" << item->getTitle() << "\t" 
                 << item->getProperty() << "\t" << item->getCost() << endl;
        }
        cout << "Total Cost of Items Rented: " << calculateTotalFees(items) << endl;
    }
};

int main() {
    vector<LibraryItem*> items = {
        new Book("Book1", "UID1", "Author1", 25),
        new Book("Book2", "UID2", "Author2", 50),
        new CD("CD1", "UID3", "Publisher1", 40),
        new DVD("DVD1", "UID4", "Publisher2", 60)
    };

    LibraryService::checkOutItems(items);

    for (auto item : items) {
        delete item;
    }
}
