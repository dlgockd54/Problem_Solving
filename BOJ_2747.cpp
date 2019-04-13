/**
 * https://www.acmicpc.net/problem/2747
 */

#include <iostream>

#define MAX 46

long long dp[MAX];

int main() {
    int n;

    scanf("%d", &n);

    for(int i = 0; i <= n; i++) {
        if(i < 2) {
            dp[i] = i;
        }
        else {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
    }

    printf("%lld\n", dp[n]);

    return 0;
}