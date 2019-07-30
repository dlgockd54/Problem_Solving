/**
 * https://www.acmicpc.net/problem/10799
 */

#include <iostream>
#include <string>

using namespace std;

int solution(string& str) {
    int ret = 0;
    int numOfRod = 0;
    int length = str.length();

    for(int i = 1; i < length; i++) {
        if(str[i] == '(') {
            if(str[i - 1] == '(') {
                ret++;
                numOfRod++;
            }
        }
        else {
            if(str[i - 1] == '(') {
                ret += numOfRod;
            }
            else {
                numOfRod--;
            }
        }
    }

    return ret;
}

int main() {
    string inputStr;

    getline(cin, inputStr);

    printf("%d\n", solution(inputStr));

    return 0;
}