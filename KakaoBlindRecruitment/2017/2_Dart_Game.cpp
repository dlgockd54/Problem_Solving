#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int calculatePoint(string dartResult) {
    int answer = 0;
    int length = dartResult.length();

    answer += (dartResult[0] - '0');

    for (int i = 1; i < length; i++) {
        if (dartResult[i] == '0') {
            answer *= 10;
        } else if (dartResult[i] == '*') {
            answer *= 2;
        } else if (dartResult[i] == '#') {
            answer *= -1;
        } else if (dartResult[i] == 'S') {
            answer = (int) pow(answer, 1);
        } else if (dartResult[i] == 'D') {
            answer = (int) pow(answer, 2);
        } else if (dartResult[i] == 'T') {
            answer = (int) pow(answer, 3);
        }
    }

    return answer;
}

int solution(string str) {
    int length = str.length();
    int answer = 0;
    string singleTry = "";
    vector<string> splittedTry;

    for (int i = 0, count = 0; i < length; i++) {
        singleTry += str[i];

        if (str[i] == '1' && str[i + 1] == '0') {
            i++;
            singleTry += str[i];
        }

        if (i == length - 1 || (str[i + 1] >= '0' && str[i + 1] <= '9')) {
            splittedTry.push_back(singleTry);

            answer += calculatePoint(splittedTry[count]);

            if (count > 0 && singleTry[singleTry.length() - 1] == '*') {
                answer += calculatePoint(splittedTry[count - 1]);
            }

            count++;
            singleTry = "";
        }
    }

    return answer;
}

int main() {
    string str = "1S2D*3T";
    cout << solution(str) << endl;

    str = "1D2S#10S";
    cout << solution(str) << endl;

    str = "1D2S0T";
    cout << solution(str) << endl;

    str = "1S*2T*3S";
    cout << solution(str) << endl;

    str = "1D#2S*3S";
    cout << solution(str) << endl;

    str = "1T2D3D#";
    cout << solution(str) << endl;

    str = "1D2S3T*";
    cout << solution(str) << endl;

    return 0;
}