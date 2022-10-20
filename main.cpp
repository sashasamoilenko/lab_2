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
        for(int i = digits_str.size()-1; i >= 0 ; --i){
            digits.push_back(digits_str[i] - '0');
        }
    }

    Lint operator+(Lint other) {
        Lint res;
        int carry = 0;

        int max_len = digits.size() > other.digits.size() ? digits.size() : other.digits.size();

        for (int i = 0; i < max_len; ++i) {
            int d = 0;
            if (i < digits.size()) {
                d += digits[i];
            }

            if (i < other.digits.size()) {
                d += other.digits[i];
            }

            res.digits.push_back((d + carry) % 10);
            carry = (d + carry) / 10;
        }

        if (carry > 0){
            res.digits.push_back(carry);
        }
        return res;
    }
//    static void setMultMode(Multer *newMulter) {
//       multer = newMulter;
//    }

    void print() {
        for (int i = digits.size()-1; i >= 0 ; --i) {
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
    Lint a("133"), b("1928"), c, d, e;
    a.print();
    c = a+b;
    c.print();
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
