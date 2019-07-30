/**
 * https://www.acmicpc.net/problem/2579
 */

#include <iostream>
#include <algorithm>

#define MAX 300

using namespace std;

int stairs[MAX];
int dp[MAX][2];

int main() {
    int numOfStairs = 0;
    int result = 0;

    scanf("%d", &numOfStairs);

    for (int i = 0; i < numOfStairs; i++) {
        int stairValue = 0;

        scanf("%d", &stairValue);

        stairs[i] = stairValue;
    }

    dp[0][0] = dp[0][1] = stairs[0];

    for (int i = 1; i < numOfStairs; i++) {
        if(i == 1) {
            dp[i][0] = dp[0][1] + stairs[1];
            dp[i][1] = stairs[1];
        }
        else {
            dp[i][0] = dp[i - 1][1] + stairs[i];
            dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + stairs[i];
        }
    }
    
    result = max(dp[numOfStairs - 1][0], dp[numOfStairs - 1][1]);

    printf("%d\n", result);

    return 0;
}