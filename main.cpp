#include <iostream>

class Multer {
public:
    virtual void multiply() = 0;
};

class Karatsuba : public Multer {
public:
     void multiply() {
         //...
     }
};

class Strassen : public Multer {
public:
    void multiply() {
        //...
    }
};

class Lint {
private:
    static Multer *multer;
public:
    static void setMultMode(Multer *newMulter) {
       multer = newMulter;
    }

    Lint operator* (Lint other) {
        multer->multiply();
    }
};
int main() {
    Lint a = "837173432094389813435565409985", b, c, d, e;
    b = "19";
    std::cin >> c;

    Lint::setMultMode(new Karatsuba());

    std::cout << a * (b + c) << std::endl;

    return 0;

};
