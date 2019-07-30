/**
 * https://www.acmicpc.net/problem/1932
 */

#include <iostream>

#define MAX 500

using namespace std;

int triangle[MAX][MAX];
int dp[MAX][MAX];

int solution(int n) {
    int ret = 0;

    dp[0][0] = triangle[0][0];

    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            int sum = triangle[i][j];

            if(j == 0) {
                sum = sum + dp[i-1][j];
            }
            else if(j == i) {
                sum = sum + dp[i-1][j-1];
            }
            else {
                sum = sum + max(dp[i-1][j-1], dp[i-1][j]);
            }

            dp[i][j] = sum;
        }
    }

    for(int i = 0;i<n;i++) {
        if(ret < dp[n - 1][i]) {
            ret = dp[n-1][i];
        }
    }

    return ret;
}

int main() {
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            scanf("%d", &triangle[i][j]);
        }
    }

    printf("%d\n", solution(n));

    return 0;
}