/*
🔹 I — Interface Segregation Principle (ISP)

🧠 Definition:
Clients should not be forced to depend on interfaces they do not use.

That means:
- Break big interfaces into smaller, role-specific ones
- Each class should only implement what it actually needs

💥 Why It Matters:
- Reduces unnecessary code
- Avoids "empty method" implementations
- Makes code cleaner and easier to evolve

🧪 Real-World Analogy:
A Software Engineer codes.
A QA Tester tests.
A Manager manages.
You wouldn't ask the Manager to write unit tests or code, right?

📌 Summary:

✅ Good Practice                       ❌ Bad Practice
-------------------------------       -------------------------------
Small, focused interfaces             One fat interface for all roles
Only implement what you need          Forced to implement unused methods
More modular, role-based design       Tight coupling and bloated classes
*/


// 🛠️ Mini Project: Role-specific Interfaces

#include <iostream>

// 🎯 Small, focused interfaces
class ICode {
public:
    virtual void writeCode() = 0;
    virtual ~ICode() = default;
};

class ITest {
public:
    virtual void runTests() = 0;
    virtual ~ITest() = default;
};

class IManage {
public:
    virtual void manageTeam() = 0;
    virtual ~IManage() = default;
};

// 👨‍💻 Developer only codes
class Developer : public ICode {
public:
    void writeCode() override {
        std::cout << "Developer writing C++ code.\n";
    }
};

// 🧪 Tester only tests
class Tester : public ITest {
public:
    void runTests() override {
        std::cout << "Tester running test cases.\n";
    }
};

// 🧑‍💼 Manager only manages
class Manager : public IManage {
public:
    void manageTeam() override {
        std::cout << "Manager assigning tasks and planning sprints.\n";
    }
};

int main() {
    Developer dev;
    Tester tester;
    Manager mgr;

    dev.writeCode();
    tester.runTests();
    mgr.manageTeam();

    return 0;
}

/*
✅ ISP Applied:

Each class only implements what it needs.

Component | Responsibility
----------|-------------------------------
ICode     | Interface for coding
ITest     | Interface for testing
IManage   | Interface for managing
Developer | Only writes code
Tester    | Only runs tests
Manager   | Only manages team

No unnecessary method implementations.
No bloated interfaces. Clean and modular.
*/
