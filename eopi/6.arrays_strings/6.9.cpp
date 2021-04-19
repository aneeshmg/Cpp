// big integer multiplication
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(vector<int> t) {
    for (auto x : t)
        cout << x << " ";
    cout << endl;
}

class BigInt {
    private:
        int sign;
        vector<char> digits;

    public:
        BigInt(const int &capacity) : sign(1), digits(capacity) {}

        BigInt(const string &s) : sign(s[0] == '-' ? -1 : 1), digits(s.size() - (s[0] == '-')) {
            for (int i = s.size() -1, j = 0; i >= (s[0] == '-'); --i, ++j) {
                if (isdigit(s[i])) {
                    digits[j] = s[i] - '0';
                }
            }
        }

        BigInt operator*(const BigInt &n) const {
            BigInt result(digits.size() + n.digits.size());
            result.sign = sign * n.sign;
            int i, j;

            for (i = 0; i < n.digits.size(); ++i) {
                if (n.digits[i]) {
                    int carry = 0;
                    for (j = 0; j < digits.size() || carry; ++j) {
                        int n_digit = result.digits[i + 1] + (j < digits.size() ? n.digits[i] * digits[j] : 0) + carry;
                        result.digits[i + j] = n_digit % 10;
                        carry = n_digit / 10;
                    }
                }
            }

            if ((digits.size() == 1 && digits.front() == 0) || (n.digits.size() == 1 && n.digits.front() == 0))
                result.digits.resize(1);
            else
                result.digits.resize(i + j - 1);

            return result;
        }
};

int main() {

    // main idea is to use the algorithm to mul two numbers by hand
    BigInt a("11"), b("23"), c();

    // test in revision
    c = a * b;
    cout << c[0] << endl;
}