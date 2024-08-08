/**
 * @brief The Abstract Factory pattern provides an interface for creating families of related or dependent objects without specifying their concrete classes.
 *
 * This pattern is useful when you want to create objects that are related or dependent on each other, but you want to decouple the client code from the specific implementations of those objects. By using an abstract factory, you can create families of objects that are designed to work together, while hiding the implementation details from the client code.
 *
 * The key components of the Abstract Factory pattern are:
 * - AbstractFactory: This is an interface or abstract class that declares the methods for creating the related objects.
 * - ConcreteFactory: This is a class that implements the AbstractFactory interface and provides the concrete implementations of the creation methods.
 * - AbstractProduct: This is an interface or abstract class that declares the methods that the created objects will implement.
 * - ConcreteProduct: This is a class that implements the AbstractProduct interface and provides the specific implementation of the methods declared in the interface.
 *
 * The Abstract Factory pattern is particularly useful in scenarios where you have multiple families of related objects and you want to ensure that the objects within each family are compatible with each other. It also promotes loose coupling between the client code and the concrete implementations, making it easier to switch between different families of objects without modifying the client code.
 *
 * Use cases for the Abstract Factory pattern include:
 * - Creating objects that are part of a family or group and need to be compatible with each other.
 * - Encapsulating the creation of objects, allowing for easy substitution of different families of objects.
 * - Promoting loose coupling between the client code and the concrete implementations.
 *
 * @note The Abstract Factory pattern should be used when there is a need to create families of related objects and ensure their compatibility, while keeping the client code decoupled from the specific implementations.
 */
// Main Idea -> We Push the logic of creating the instance of Product class (or any of its subclass) inside the Factory class hierarchy.
// Pros -> 1. Avoid Tight Copting between Factory (Creation Logic) and Concrete Products
//         2. Follows Single Responsibily Principle
//         3. Follows Open/Closed Principle
//         4. Uses the Liskov Substitution Principle

#include <bits/stdc++.h>
using namespace std;

class AbstractProductA {
public:
    virtual ~AbstractProductA() = 0;
    virtual void createProductA() const = 0;
};

AbstractProductA::~AbstractProductA() {}

class ConcreteProductA1 : public AbstractProductA {
public:
    void createProductA() const override {
        cout << "Product A1 created" << endl;
    }
};

class ConcreteProductA2 : public AbstractProductA {
public:
    void createProductA() const override {
        cout << "Product A2 created" << endl;
    }
};

class AbstractProductB {
public:
    virtual ~AbstractProductB() = 0;
    virtual void createProductB() const = 0;
};

AbstractProductB::~AbstractProductB() {}

class ConcreteProductB1 : public AbstractProductB {
public:
    virtual void createProductB() const override {
        cout << "Product B1 created" << endl;
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    virtual void createProductB() const override {
        cout << "Product B2 created" << endl;
    }
};

class AbstractFactory {
public:
    virtual AbstractProductA* createProductA() const = 0;
    virtual AbstractProductB* createProductB() const = 0;
};

class ConcreteFactory1 : public AbstractFactory { // Creates Product of Type 1 (A1, B1)
public:
    AbstractProductA* createProductA() const override {
        cout << "Createing A1 from Concrete Factory 1" << endl;
        return new ConcreteProductA1();
    }
    AbstractProductB* createProductB() const override {
        cout << "Createing B1 from Concrete Factory 1" << endl;
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory { // Creates Product of Type 2 (A2, B2)
public:
    AbstractProductA* createProductA() const override {
        cout << "Createing A2 from Concrete Factory 2" << endl;
        return new ConcreteProductA2();
    }
    AbstractProductB* createProductB() const override {
        cout << "Createing B2 from Concrete Factory 2" << endl;
        return new ConcreteProductB2();
    }
};

int main() { // Client Code
    int choice; cin >> choice;
    if (choice == 1) { // We need to create products of type 1
        ConcreteFactory1* factory = new ConcreteFactory1();
        AbstractProductA* a = factory->createProductA();
        AbstractProductB* b = factory->createProductB();
        a->createProductA();
        b->createProductB();
    } else if (choice == 2) {
        ConcreteFactory2* factory = new ConcreteFactory2();
        AbstractProductA* a = factory->createProductA();
        AbstractProductB* b = factory->createProductB();
        a->createProductA();
        b->createProductB();
    }
}