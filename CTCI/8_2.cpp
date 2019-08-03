/**
 * 부분집합: 어떤 집합의 부분집합을 전부 반환하는 메서드를 작성하라.
 */

/**
 * 집합의 길이 n = 0인 경우의 부분 집합은 다음과 같다.
 * n = 0 {}
 * n = 1 {a1}, {}
 * n = 2 {a1 a2}, {a2}, {a1}, {}
 * n = 3 {a1 a2 3}, {a2 a3}, {a1 a3}, {a3}, {a1 a2}, {a2}, {a1}, {}
 * 
 * n = 3인 경우와 2인 경우의 차이를 보면, n = 3의 요소들은 n = 2인 경우의 각 요소에 a3이 추가된 경우에 n = 2인 요소들을 추가한 경우이다.
 */

#include <iostream>
#include <vector>

using namespace std;

vector< vector<char> > solution(vector<char>& arr) {
    vector< vector<char> > answer;
    int size = arr.size();

    if(size == 0) {
        answer.push_back({});
    } else {
        char lastElement = arr[size - 1];
        vector< vector<char> > returnedArr;
        int returnedArrSize = 0;

        arr.pop_back();

        returnedArr = solution(arr);
        returnedArrSize = returnedArr.size();

        for(int i = 0; i < returnedArrSize; i++) {
            vector<char> newElement = returnedArr[i];

            answer.push_back(newElement);
            newElement.push_back(lastElement);
            answer.push_back(newElement);
        }
    }

    return answer;
}

int main() {
    vector<char> arr = { 'a', 'b', 'c' };
    vector< vector<char> > resultArr = solution(arr);

    for(int i = 0; i < resultArr.size(); i++) {
        printf("{");

        for(int j = 0; j < resultArr[i].size(); j++) {
            printf(" %c ", resultArr[i][j]);
        }

        printf("}\n");
    }

    return 0;
}