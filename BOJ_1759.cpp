/**
 * https://www.acmicpc.net/problem/1759
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int L;
int C;
vector<char> strVector;

bool isAvailableString(string str) {
    int length = str.length();
    int numOfM = 0;
    int numOfJ = 0;
    bool ret = true;

    for(int i = 0; i < length; i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            numOfM++;
        }
        else {
            numOfJ++;
        }
    }

    if(numOfM < 1 || numOfJ < 2) {
        ret = false;
    }

    return ret;
}

void printString(string str, int idx) {
    string tempStr = str + strVector[idx];

    if(tempStr.length() == L) {
        if(isAvailableString(tempStr)) {
            cout << tempStr << endl;
        }
    }
    else {
        for(int i = idx + 1; i < C; i++) {
            printString(tempStr, i);
        }
    }
}

int main() {
    int rubbish = 0;
    string inputStr;

    scanf("%d %d", &L, &C);
    scanf("%d", &rubbish);

    getline(cin, inputStr);
    sort(inputStr.begin(), inputStr.end());

    for(int i = 0; i < inputStr.length(); i++) {
        if(inputStr[i] != ' ') {
            strVector.push_back(inputStr.at(i));
        }
    }

    for(int i = 0; i <= C - L; i++) {
        printString("", i);
    }

    return 0;
}
