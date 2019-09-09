#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    stack<int> stk;
public:
    int getIntToken(string &token) {
        int ret = 0;
        int length = token.length();
        bool isNegativeNum = false;

        for (int i = 0; i < length; i++) {
            if (token[i] == '-') {
                isNegativeNum = true;

                continue;
            }

            ret = ret * 10 + (token[i] - '0');
        }

        if (isNegativeNum) {
            ret = ret * -1;
        }

        return ret;
    }

    int evalRPN(vector<string> &tokens) {
        int size = tokens.size();
        int answer = 0;

        for (int i = 0; i < size; i++) {
            int top1 = 0;
            int top2 = 0;

            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                if (!stk.empty()) {
                    top1 = stk.top();
                    top2 = 0;

                    stk.pop();

                    if (!stk.empty()) {
                        top2 = stk.top();

                        stk.pop();

                        if (tokens[i] == "+") {
                            stk.push(top2 + top1);
                        } else if (tokens[i] == "-") {
                            stk.push(top2 - top1);
                        } else if (tokens[i] == "*") {
                            stk.push(top2 * top1);
                        } else if (tokens[i] == "/") {
                            stk.push(top2 / top1);
                        }
                    }
                }
            } else {
                stk.push(getIntToken(tokens[i]));
            }
        }

        answer = stk.top();

        return answer;
    }
};

int main() {
    Solution *sol;
    vector<string> tokens;

    sol = new Solution();
    tokens = {"2", "1", "+", "3", "*"};
    cout << sol->evalRPN(tokens) << endl;

    delete sol;

    sol = new Solution();
    tokens = {"4", "13", "5", "/", "+"};
    cout << sol->evalRPN(tokens) << endl;
    delete sol;

    sol = new Solution();
    tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << sol->evalRPN(tokens) << endl;
    delete sol;

    return 0;
}