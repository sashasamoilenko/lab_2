#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Multer {
public:
   virtual void multiply() = 0;
};



//class Strassen : public Multer {
//public:
//    void multiply() {
        //...
//    }
//};

class Lint {
private:

    static Multer *multer;
public:
    vector<int> digits;
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
        try
        {
            if (digits.size() < other.digits.size() )
                throw "You subtracted from the larger number the smaller one";
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

                //cout << d << endl;
                res.digits.push_back(d);
            }

            return res;
        }
        catch (const char* exception)
        {
            std::cerr << "Error: " << exception << '\n';
        }
        return Lint();
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
    friend Lint Karat_mult (Lint a, Lint b);
   // friend class Karatsuba::Lint();
};

Lint Karat_mult (Lint a, Lint b) {
    Lint res, a_beg, a_end, b_beg, b_end, prod10, prod30;
    int c = 0, div = 0;
    int max_len = a.digits.size() > b.digits.size() ? a.digits.size() : b.digits.size();

    if (max_len <= 10){
        return a * b;
    }

    c = a.digits.size() - b.digits.size();

    if (max_len % 2 == 0 && c > 0){
        for (int i = max_len -1 ; i > max_len - c - 1; --i){
           b.digits.push_back(0);
        }
        div = max_len / 2;
    }
    else if (max_len % 2 == 0 && c < 0) {
        for (int i = max_len - 1; i > max_len - 1 + c; --i){
            a.digits.push_back(0);
        }
        div = max_len / 2;
    }
    else if (max_len % 2 == 0 && c == 0) {
        div = max_len / 2;
    }

    if (max_len % 2 != 0 && c > 0){
        a.digits.push_back(0);
        for (int i = max_len; i > max_len - c; --i){
            b.digits.push_back(0);
        }
        div = max_len / 2 + 1;
    }
    else if (max_len % 2 != 0 && c < 0) {
        b.digits.push_back(0);
        for (int i = max_len; i > max_len + c; --i){
            a.digits.push_back(0);
        }
        div = max_len / 2 + 1;
    }
    else if (max_len % 2 != 0 && c == 0) {
        b.digits.push_back(0);
        a.digits.push_back(0);
        div = max_len / 2 + 1;
    }

    for (int i = 0; i < div; ++i) {
        a_beg.digits.push_back(a.digits[i+div]);
        a_end.digits.push_back(a.digits[i]);
        b_beg.digits.push_back(b.digits[i+div]);
        b_end.digits.push_back(b.digits[i]);
    }

    Lint prod1 = Karat_mult (a_beg, b_beg);
    Lint prod2 = Karat_mult (a_end, b_end);
    Lint prod3 = Karat_mult (a_beg + a_end, b_beg + b_end) - prod1 - prod2;

    for (int i = 0; i < 2 * div; ++i) {
        prod10.digits.push_back(0);
    }
    for (int i = 0; i < prod1.digits.size() - 1; ++i) {
        prod10.digits.push_back(prod1.digits[i]);
    }

    for (int i = 0; i < div; ++i) {
        prod30.digits.push_back(0);
    }
    for (int i = 0; i < prod3.digits.size() - 1; ++i) {
        prod30.digits.push_back(prod3.digits[i]);
    }

    res = prod10 + prod30 + prod2;

    return res;
}

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

class Karatsuba : public Multer {
private:
    Lint res, a_beg, a_end, b_beg, b_end, ten_2div, ten_div;
    int c = 0, div = 0;

public:
    Lint Karat_mult(Lint a, Lint b){
            int max_len = a.digits.size() > b.digits.size() ? a.digits.size() : b.digits.size();

            if (max_len <= 1){
                return a * b;
            }

            c = a.digits.size() - b.digits.size();
            cout << c << endl;

            if (max_len % 2 == 0 && c > 0){
                for (int i = max_len - 1; i > max_len - c - 1; --i) {
                    b.digits.push_back(0);
                }
            }
            if (max_len % 2 == 0){
                div = max_len / 2;
            }
            else{
                div = max_len / 2 + 1;
            }

            cout << div << endl;

            for (int i = 0; i < div; ++i) {
                a_beg.digits.push_back(a.digits[i + div]);
                cout << a.digits[i + div] << endl;
                a_end.digits.push_back(a.digits[i]);
                cout << a.digits[i] << endl;
                b_beg.digits.push_back(b.digits[i + div]);
                cout << b.digits[i + div] << endl;
                b_end.digits.push_back(b.digits[i]);
                cout << b.digits[i] << endl;
            }

            Lint prod1 = Karat_mult (a_beg, b_beg);
            cout << prod1 << endl;
            Lint prod2 = Karat_mult (a_end, b_end);
            cout << prod2 << endl;
            Lint prod3 = Karat_mult (a_beg + a_end, b_beg + b_end) - prod1 - prod2;
            cout << prod3 << endl;

            for (int i = 0; i < 2 * div; ++i) {
                ten_2div.digits.push_back(0);
            }
            ten_2div.digits.push_back(1);

            for (int i = 0; i < div; ++i) {
                ten_div.digits.push_back(0);
            }
            ten_div.digits.push_back(1);

            cout << ten_2div << endl;

            res = prod1 * ten_2div + prod3 * ten_div + prod2;

            return res;
    }
};
int main() {
    Lint a("23564567657888"), b("485902009"), c, d, e;
    //c = Karat_mult(a,b);
    c = a - b;
    cout << c << endl;

//    Lint test;
//    test.test();

//    Lint *pTest = new Lint();
//    pTest->test();

//    Lint::setMultMode(new Karatsuba());

//    std::cout << a * (b + c) << std::endl;

    return 0;

}
