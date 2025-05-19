#include <iostream>
#include <string>

// Base class
class Person {
protected:
    std::string name;
    int age;
public:
    Person(const std::string& n = "", int a = 0) : name(n), age(a) {}
    virtual ~Person() {}

    virtual void input(std::istream& in) {
        std::cout << "Enter name: ";
        in >> name;
        std::cout << "Enter age: ";
        in >> age;
    }

    virtual void output(std::ostream& out) const {
        out << "Name: " << name << "\nAge: " << age << std::endl;
    }

    friend std::istream& operator>>(std::istream& in, Person& p) {
        p.input(in);
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Person& p) {
        p.output(out);
        return out;
    }
};

// Derived class: Woman
class Woman : virtual public Person {
protected:
    std::string maidenName;
public:
    Woman(const std::string& n = "", int a = 0, const std::string& maiden = "")
        : Person(n, a), maidenName(maiden) {
    }
    virtual ~Woman() {}

    void input(std::istream& in) override {
        Person::input(in);
        std::cout << "Enter maiden name: ";
        in >> maidenName;
    }

    void output(std::ostream& out) const override {
        Person::output(out);
        out << "Maiden Name: " << maidenName << std::endl;
    }
};

// Derived class: Worker
class Worker : virtual public Person {
protected:
    std::string position;
    double salary;
public:
    Worker(const std::string& n = "", int a = 0, const std::string& pos = "", double sal = 0.0)
        : Person(n, a), position(pos), salary(sal) {
    }
    virtual ~Worker() {}

    void input(std::istream& in) override {
        Person::input(in);
        std::cout << "Enter position: ";
        in >> position;
        std::cout << "Enter salary: ";
        in >> salary;
    }

    void output(std::ostream& out) const override {
        Person::output(out);
        out << "Position: " << position << "\nSalary: " << salary << std::endl;
    }
};

// Multiple inheritance: WorkerWoman
class WorkerWoman : public Woman, public Worker {
public:
    WorkerWoman(const std::string& n = "", int a = 0,
        const std::string& maiden = "", const std::string& pos = "", double sal = 0.0)
        : Person(n, a), Woman(n, a, maiden), Worker(n, a, pos, sal) {
    }

    ~WorkerWoman() override {}

    void input(std::istream& in) override {
        std::cout << "--- Input Worker-Woman ---" << std::endl;
        Person::input(in); // Input shared base
        std::cout << "Enter maiden name: ";
        in >> maidenName;
        std::cout << "Enter position: ";
        in >> position;
        std::cout << "Enter salary: ";
        in >> salary;
    }

    void output(std::ostream& out) const override {
        out << "--- Worker-Woman Info ---" << std::endl;
        Person::output(out);
        out << "Maiden Name: " << maidenName << std::endl;
        out << "Position: " << position << std::endl;
        out << "Salary: " << salary << std::endl;
    }

    friend std::istream& operator>>(std::istream& in, WorkerWoman& ww) {
        ww.input(in);
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const WorkerWoman& ww) {
        ww.output(out);
        return out;
    }
};

int main() {
    WorkerWoman ww("Anna", 30, "Petrova", "Engineer", 8500.0);

    std::cout << ww;

    std::cout << "\nNow enter new data for Worker-Woman:\n";
    std::cin >> ww;

    std::cout << "\nUpdated data:\n" << ww;

    return 0;
}
