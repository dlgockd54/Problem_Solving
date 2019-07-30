#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool isAvailableStr(string& str) {
    int length = str.length();
    int numOfSpace = 0;
    bool ret = false;

    for(int i = 0; i < length; i++) {
        if(str[i] == ' ') {
            numOfSpace++;
        }
    }

    if(numOfSpace == 6) {
        ret = true;
    }

    return ret;
}

void printStr(string& str, vector<int>& S, int k) {
    int length = str.length();
    char* arrStr = (char*)malloc(sizeof(char) * length);
    char* tokStr = nullptr;

    strcpy(arrStr, str.c_str());

    tokStr = strtok(arrStr, " ");

    while(tokStr != nullptr) {
        string resultStr = string(tokStr);
        int index = (resultStr[0] - '0');

        if(resultStr.length() > 1) {
            index = index * 10 + (resultStr[1] - '0');
        }

        printf("%d ", S[index]);
        tokStr = strtok(nullptr, " ");
    }

    printf("\n");
}

void solution(string tempStr, int idx, int k, vector<int>& S) {
    string str = tempStr + " " + to_string(idx);

    if(isAvailableStr(str)) {
        printStr(str, S, k);
    }
    else {
        for(int i = idx + 1; i < k; i++) {
            solution(str, i, k, S);
        }
    }
}

int main() {
    while(true) {
        int k;
        vector<int> S;

        scanf("%d", &k);

        if(k == 0) {
            break;
        }

        for(int i = 0; i < k; i++) {
            int input;

            scanf("%d", &input);

            S.push_back(input);
        }

        sort(S.begin(), S.end());

        for(int i = 0; i <= (k - 6); i++) {
            solution("", i, k, S);
        }

        printf("\n");
    }

    return 0;
}