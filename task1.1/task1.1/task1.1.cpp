#include <iostream>

class A {
public:
    int a;
};

// Non-virtual inheritance
class B1 : public A {
public:
    int b;
};

class C1 : public A {
public:
    int c;
};

class D1 : public B1, public C1 {
public:
    int d;
};

// Virtual inheritance
class B2 : virtual public A {
public:
    int b;
};

class C2 : virtual public A {
public:
    int c;
};

class D2 : public B2, public C2 {
public:
    int d;
};

int main() {
    std::cout << "--- Without Virtual Inheritance ---" << std::endl;
    std::cout << "Size of A: " << sizeof(A) << " bytes" << std::endl;
    std::cout << "Size of B1: " << sizeof(B1) << " bytes" << std::endl;
    std::cout << "Size of C1: " << sizeof(C1) << " bytes" << std::endl;
    std::cout << "Size of D1: " << sizeof(D1) << " bytes" << std::endl;

    std::cout << "\n--- With Virtual Inheritance ---" << std::endl;
    std::cout << "Size of A: " << sizeof(A) << " bytes" << std::endl;
    std::cout << "Size of B2: " << sizeof(B2) << " bytes" << std::endl;
    std::cout << "Size of C2: " << sizeof(C2) << " bytes" << std::endl;
    std::cout << "Size of D2: " << sizeof(D2) << " bytes" << std::endl;

    return 0;
}
