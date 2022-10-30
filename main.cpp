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

    Lint operator*(Lint other) {
        Lint res;
        int d = 0, carry1 = 0, carry2 = 0, c = 0;

        int max_len = digits.size() > other.digits.size() ? digits.size() : other.digits.size();
        vector<int>inter (2 * max_len);
            for (int i = 0; i < digits.size(); ++i){
                for (int j = 0; j < other.digits.size(); ++j){
                    inter[i + j] += digits[i] * other.digits [j];
                }
            }

            for (int i = 0; i < 2 * max_len; ++i) {
                c = inter[i] + carry1 + 10 * carry2;
                d = c % 10;
                carry1 = (c / 10) % 10;
                carry2 = c / 100;
                res.digits.push_back(d);
            }

        return res;

    }

    Lint operator-(Lint other) {
        Lint res;
        int d = 0;
        int m = 0;

        int max_len = digits.size() > other.digits.size() ? digits.size() : other.digits.size();

        //if (max_len == digits.size() && max_len == other.digits.size() && digits[max_len - 1] == other.digits[max_len - 1]) {
         //   max_len -= 1;
        //}

        for (int i = 0; i < max_len; ++i) {

            if (i < digits.size()) {
                d = digits[i]-m;
                m = 0;
            }

            if (i < other.digits.size()) {
                d -= other.digits[i];
            }

            if (d < 0) {
                d += 10;
                m = 1;
            }

            cout << d << endl;
            res.digits.push_back(d);
        }

        return res;
    }

    Lint operator+(Lint other) {
        Lint res;
        int d = 0;

        int max_len = digits.size() > other.digits.size() ? digits.size() : other.digits.size();

        for (int i = 0; i < max_len; ++i) {

            if (i < digits.size()) {
                d += digits[i];
            }

            if (i < other.digits.size()) {
                d += other.digits[i];
            }

            res.digits.push_back(d % 10);
            d = d / 10;
        }

        if (d > 0){
           res.digits.push_back(d);
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

    friend ostream& operator<<(ostream &stream, Lint x);
};

ostream& operator<<(ostream &stream, Lint x) {
    int counter = 0;
    int i = x.digits.size()-1;
    while (x.digits[i] == 0) {
        counter += 1;
        i -= 1;
    }

    for (int i = x.digits.size()-1-counter; i >= 0; --i){
        stream << x.digits[i];
    }
    stream << endl;
    return stream;
}
int main() {
    Lint a("9900"), b("99"), c, d, e;
    a.print();
    c = a*b;
    c.print();
    cout << c << endl;
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
