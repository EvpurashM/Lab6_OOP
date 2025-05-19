#include <iostream>
#include <cmath> // for sqrt()

// Define PI if not available
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Abstract base class
class Figure {
public:
    virtual double perimeter() const = 0; // Pure virtual function
    virtual ~Figure() {}
};

// Rectangle class
class Rectangle : public Figure {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double perimeter() const override {
        return 2 * (width + height);
    }
};

// Circle class
class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double perimeter() const override {
        return 2 * M_PI * radius;
    }
};

// Right triangle class
class RightTriangle : public Figure {
private:
    double a, b; // legs
public:
    RightTriangle(double sideA, double sideB) : a(sideA), b(sideB) {}
    double perimeter() const override {
        return a + b + std::sqrt(a * a + b * b); // hypotenuse
    }
};

// Trapezoid class
class Trapezoid : public Figure {
private:
    double a, b, c, d;
public:
    Trapezoid(double s1, double s2, double s3, double s4)
        : a(s1), b(s2), c(s3), d(s4) {
    }
    double perimeter() const override {
        return a + b + c + d;
    }
};

int main() {
    // Array of pointers to Figure
    Figure* figures[4];

    figures[0] = new Rectangle(4, 6);
    figures[1] = new Circle(3);
    figures[2] = new RightTriangle(3, 4);
    figures[3] = new Trapezoid(3, 5, 4, 6);

    std::cout << "Perimeters of figures:\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << "Figure " << i + 1 << ": " << figures[i]->perimeter() << std::endl;
    }

    // Clean up memory
    for (int i = 0; i < 4; ++i) {
        delete figures[i];
    }

    return 0;
}
