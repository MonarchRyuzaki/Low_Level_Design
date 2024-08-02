#include <bits/stdc++.h>
using namespace std;

// Main Idea -> We Push the logic of creating the instance of Product class (or any of its subclass) inside the Factory class hierarchy. 
//              This way we dont have to repeat the logic to create instance everytime. We use upcasting (use Factory as a interface) to use its sub classes.
//              We can also add multiple logic (based on different scenario) to create a instance

// Pros -> 1. Avoid Tight Copting between Factory (Creation Logic) and Concrete Products
//         2. Follows Single Responsibily Principle
//         3. Follows Open/Closed Principle
//         4. Uses the Liskov Substitution Principle

// Cons -> 1. Can be Complicated at first because we need to add a lot of classes to implement.
//            Especially if done in existing code  

class Product {
public:
    virtual ~Product() {}
    virtual string Operation() const = 0;
};

class ConcreteProduct1 : public Product {
public:
    string Operation() const override {
        return "{Result of ConcreteProduct1}";
    }
};

class ConcreteProduct2 : public Product {
public:
    string Operation() const override {
        return "{Result of ConcreteProduct2}";
    }
};


class Factory{
public:
    virtual ~Factory() {};
    virtual Product* FactoryMethod() const  = 0;
    string someOperation() const {
        Product* product = this->FactoryMethod();
        string result = "Creator: The same creator's code has just worked with " + product->Operation();
        delete product;
        return result;
    }
};

class ConcreteFactory1 : public Factory {
public:
    Product* FactoryMethod() const {
        return new ConcreteProduct1();
    }
};

class ConcreteFactory2 : public Factory {
public:
    Product* FactoryMethod() const {
        return new ConcreteProduct1();
    }
};

void clientCode(const Factory& factory) {
    cout << "Client: I'm not aware of the creator's class, but it still works.\n" << factory.someOperation() << endl;
}

int main() {
    cout << "App: Launched with the ConcreteCreator1.\n";
  Factory* creator = new ConcreteFactory1();
  clientCode(*creator);
  cout << endl;
  cout << "App: Launched with the ConcreteCreator2.\n";
  Factory* creator2 = new ConcreteFactory2();
  clientCode(*creator2);

  delete creator;
  delete creator2;
  return 0;
}
