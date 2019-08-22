#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void printResult(int n, int length) {
    string nToStr = "";

    while (n > 0) {
        nToStr += (n % 2 == 1) ? "#" : " ";

        n /= 2;
    }

    reverse(nToStr.begin(), nToStr.end());

    if (nToStr.length() < length) {
        int numOfSpace = length - nToStr.length();

        for (int i = 0; i < numOfSpace; i++) {
            nToStr = " " + nToStr;
        }
    }

    cout << nToStr << endl;
}

int main() {
    int n;
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = {30, 1, 21, 17, 28};

    n = arr1.size();

    for (int i = 0; i < n; i++) {
        int orResult = arr1[i] | arr2[i];

        printResult(orResult, n);
    }

    cout << endl;

    arr1 = {46, 33, 33, 22, 31, 50};
    arr2 = {27, 56, 19, 14, 14, 10};

    n = arr1.size();

    for (int i = 0; i < n; i++) {
        int orResult = arr1[i] | arr2[i];

        printResult(orResult, n);
    }

    return 0;
}