#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    string nToStr = "";
    vector<string> answer;

    for (int i = 0; i < n; i++) {
        int orValue = arr1[i] | arr2[i];

        while (orValue > 0) {
            nToStr += (orValue % 2 == 1) ? "#" : " ";

            orValue /= 2;
        }

        reverse(nToStr.begin(), nToStr.end());

        if (nToStr.length() < n) {
            int length = nToStr.length();
            int numOfSpace = n - length;

            for (int j = 0; j < numOfSpace; j++) {
                nToStr = " " + nToStr;
            }
        }

        answer.push_back(nToStr);

        nToStr = "";
    }

    return answer;
}

int main() {
    int n;
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = {30, 1, 21, 17, 28};
    vector<string> result = solution(arr1.size(), arr1, arr2);

    n = arr1.size();
    for (int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }

    cout << endl;

    arr1 = {46, 33, 33, 22, 31, 50};
    arr2 = {27, 56, 19, 14, 14, 10};

    n = arr1.size();
    result = solution(n, arr1, arr2);

    for (int i = 0; i < n; i++) {
        cout << result[i] << endl;
    }

    return 0;
}