#include <iostream>
#include <vector>
using namespace std;
//class Multer {
//public:
//    virtual void multiply() = 0;
//};

//class Karatsuba : public Multer {
//public:
//     void multiply() {
         //...
//     }
//};

//class Strassen : public Multer {
//public:
//    void multiply() {
        //...
//    }
//};

class Lint {
private:
    vector<int> digits;
//    static Multer *multer;
public:
    Lint() {
    }

    Lint(string digits_str) {
        for(int i = 0; i < digits_str.size(); ++i){
            digits.push_back(digits_str[i] - '0');
        }
    }
//    static void setMultMode(Multer *newMulter) {
//       multer = newMulter;
//    }

    void print() {
        for (int i = 0; i < digits.size(); ++i) {
            cout << digits[i];
        }
        cout << endl;
    }
    Lint operator* (Lint other) {
          return other;
//        multer->multiply();
    }
};
int main() {
    Lint a("83717"), b, c, d, e;
    a.print();
//    b = "19";
//    std::cin >> c;

//    Lint test;
//    test.test();

//    Lint *pTest = new Lint();
//    pTest->test();

//    Lint::setMultMode(new Karatsuba());

//    std::cout << a * (b + c) << std::endl;

    return 0;

}
