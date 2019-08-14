#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string insertStr = "()";

        if (n == 1) {
            answer.push_back(insertStr);
        } else {
            vector<string> returnedArr = generateParenthesis(n - 1);
            int size = returnedArr.size();

            for (int i = 0; i < size; i++) {
                int length = returnedArr[i].length();

                for (int j = 0; j < length; j++) {
                    string newStr = returnedArr[i];

                    newStr.insert(j, insertStr);

                    if(find(answer.begin(), answer.end(), newStr) == answer.end()) {
                        answer.push_back(newStr);
                    }
                }
            }
        }

        return answer;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> result = sol.generateParenthesis(1);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    result = sol.generateParenthesis(2);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    result = sol.generateParenthesis(3);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    result = sol.generateParenthesis(4);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}