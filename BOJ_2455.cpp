/**
 * https://www.acmicpc.net/problem/2455
 */

#include <iostream>

using namespace std;

int main() {
    int currentNum = 0;
    int result = 0;

    for(int i = 1; i <= 4; i++) {
        int in = 0;
        int out = 0;

        scanf("%d %d", &out, &in);

        currentNum -= out;
        result = result > currentNum ? result : currentNum;
        currentNum += in;
        result = result > currentNum ? result : currentNum;
    }

    printf("%d\n", result);

    return 0;
}