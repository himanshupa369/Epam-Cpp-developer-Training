#include <iostream>
#include <string>

// Abstract base class (Interface-like behavior)
class Document {
public:
    virtual void Serialize() = 0; // Pure virtual function

    // You can still have other members
    void PrintType() {
        std::cout << "This is a document.\n";
    }

    virtual ~Document() {} // Virtual destructor
};

// Derived class: TextDocument
class TextDocument : public Document {
public:
    void Serialize() override {
        std::cout << "Serializing text document...\n";
    }
};

// Derived class: XMLDocument
class XMLDocument : public Document {
public:
    void Serialize() override {
        std::cout << "Serializing XML document...\n";
    }
};

// Client code – works with base class pointer
void Write(Document* doc) {
    doc->Serialize();  // Calls derived class implementation
}

int main() {
    TextDocument textDoc;
    XMLDocument xmlDoc;

    // Base class pointer to derived object
    Document* doc1 = &textDoc;
    Document* doc2 = &xmlDoc;

    // Calls overridden functions
    Write(doc1); // Output: Serializing text document...
    Write(doc2); // Output: Serializing XML document...

    return 0;
}
