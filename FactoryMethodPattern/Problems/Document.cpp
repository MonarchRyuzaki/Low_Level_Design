#include <bits/stdc++.h>
using namespace std;

class Document {
public:
    virtual void create() = 0;
    virtual ~Document(){}
};

class WordDocument : public Document {
public:
    void create() override {
        cout << "Creating a Word Document" << endl;
    }
};

class PDFDocument : public Document {
public:
    void create() override {
        cout << "Creating a PDF Document" << endl;
    }
};

class Creator {
public:
    virtual Document* createDocument() = 0;
    virtual ~Creator(){} 
};

class WordCreator : public Creator {
public:
    Document* createDocument() {
        return new WordDocument();
    }
};

class PDFCreator : public Creator {
public:
    Document* createDocument() {
        return new PDFDocument();
    }
};

void clientCode(Creator &creator) {
    Document* doc = creator.createDocument();
    doc->create();
}

int main() {
    PDFCreator pdf;
    WordCreator word;
    clientCode(pdf);
    clientCode(word);
}
