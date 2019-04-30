/**
 * https://www.acmicpc.net/problem/2661
 */

#include <iostream>
#include <string>

using namespace std;

bool isGoodPermutation(string str) {
    int length = str.length();

    for(int newStrLength = 1; newStrLength <= length / 2; newStrLength++) {
        int idx1 = length - newStrLength;
        int idx2 = idx1 - newStrLength;
        string str1 = str.substr(idx1, newStrLength);
        string str2 = str.substr(idx2, newStrLength);

        if(str1.compare(str2) == 0) {
            return false;
        }
    }

    return true;
}

int solution(int N, string str) {
    int result = 0;

    if(str.length() == N) {
        if(isGoodPermutation(str)) {
            cout << str << endl;

            result = 1;
        }
    }
    else {
        for(int i = 1; i <= 3; i++) {
            if(isGoodPermutation(str + to_string(i))) {
                if(solution(N, str + to_string(i))) {
                    result = 1;

                    break;
                }
            }
        }    
    }

    return result;
}

int main() {
    int N = 0;

    scanf("%d", &N);

    for(int i = 1; i <= 3; i++) {
        if(solution(N, to_string(i))) {
            break;
        }
    }

    return 0;
}
