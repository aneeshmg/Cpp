// evaluate reverse polish notation (use stack)
#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

int eval(const string &s) {
    stack<int> eval_stack;
    stringstream ss(s);
    string symbol;

    while (getline(ss, symbol, ',')) {
        if (symbol == "+" || symbol == "-" || symbol == "*" || symbol == "/") {
            int y = eval_stack.top();
            eval_stack.pop();
            int x = eval_stack.top();
            eval_stack.pop();
            switch (symbol.front()) {
                case '+': eval_stack.emplace(x + y);
                    break;
                case '-': eval_stack.emplace(x - y);
                    break;
                case '*': eval_stack.emplace(x * y);
                    break;
                case '/': eval_stack.emplace(x / y);
                    break;
            }
        } else {
            eval_stack.emplace(stoi(symbol));
        }
    }

    return eval_stack.top();
}

int main() {

    // test in rev
}