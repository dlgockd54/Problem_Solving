#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

bool isStrAllAlphabet(string str) {
    bool answer = true;
    int length = str.length();

    for (int i = 0; i < length; i++) {
        if (str[i] < 'a' || str[i] > 'z') {
            answer = false;
        }
    }

    return answer;
}

vector<string> getSplitArr(string& str) {
    vector<string> ret;
    int length = str.length();

    for (int i = 0; i < length - 1; i++) {
        string subStr = "";
        subStr += str[i];
        subStr += str[i + 1];

        if (isStrAllAlphabet(subStr)) {
            ret.push_back(subStr);
        }
    }

    return ret;
}

vector<string> getIntersectionResult(vector<string>& arr1, vector<string>& arr2) {
    vector<string> intersectionResult;

    for (int i = 0; i < arr1.size(); i++) {
        if (find(arr2.begin(), arr2.end(), arr1[i]) != arr2.end()) {
            intersectionResult.push_back(arr1[i]);
        }
    }

    return intersectionResult;
}

vector<string> getUnionResult(vector<string>& arr1, vector<string>& arr2) {
    vector<string> unionResult;

    if (arr1.size() > arr2.size()) {
        for (int i = 0; i < arr1.size(); i++) {
            unionResult.push_back(arr1[i]);
        }

        for (int i = 0; i < arr2.size(); i++) {
            if (find(unionResult.begin(), unionResult.end(), arr2[i]) == unionResult.end()) {
                unionResult.push_back(arr2[i]);
            }
        }
    } else {
        for (int i = 0; i < arr2.size(); i++) {
            unionResult.push_back(arr2[i]);
        }

        for (int i = 0; i < arr1.size(); i++) {
            if (find(unionResult.begin(), unionResult.end(), arr1[i]) == unionResult.end()) {
                unionResult.push_back(arr1[i]);
            }
        }
    }

    return unionResult;
}

int solution(string str1, string str2) {
    vector<string> intersectionResult;
    vector<string> unionResult;
    vector<string> splitArr1;
    vector<string> splitArr2;
    int length1 = str1.length();
    int length2 = str2.length();
    int sizeOfIntersection = 0;
    int sizeOfUnion = 0;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    splitArr1 = getSplitArr(str1);
    splitArr2 = getSplitArr(str2);
    intersectionResult = getIntersectionResult(splitArr1, splitArr2);
    unionResult = getUnionResult(splitArr1, splitArr2);

    sizeOfIntersection = intersectionResult.size();
    sizeOfUnion = unionResult.size();

    if (sizeOfUnion == 0) {
        return 65536;
    }

    return (int) ((float) sizeOfIntersection / (float) sizeOfUnion * 65536);
}

int main() {
    string str1 = "FRANCE";
    string str2 = "french";

    cout << solution(str1, str2) << endl;

    str1 = "handshake";
    str2 = "shake hands";
    cout << solution(str1, str2) << endl;

    str1 = "aa1+aa2";
    str2 = "AAAA12";
    cout << solution(str1, str2) << endl;

    str1 = "E=M*C^2";
    str2 = "e=m*c^2";
    cout << solution(str1, str2) << endl;

    return 0;
}