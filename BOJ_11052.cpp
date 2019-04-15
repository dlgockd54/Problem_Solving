/**
 * https://www.acmicpc.net/problem/11052
 */

#include <iostream>

#define MAX 1001

int P[MAX];
int dp[MAX];

int main() {
    int N;

    scanf("%d", &N);

    for(int i = 1; i <= N; i++) {
        scanf("%d", &P[i]);
    }

    for(int i = 1; i <= N; i++) {
        int max = 0;

        for(int j = 1; j <= i; j++) {
            int tempMax = 0;

            if(j < i) {
                tempMax = dp[j] + dp[i - j];
            }
            else {
                tempMax = P[i];
            }

            max = max > tempMax ? max : tempMax;
        }

        dp[i] = max;
    }

    printf("%d\n", dp[N]);

    return 0;
}