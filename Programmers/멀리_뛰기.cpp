#include <iostream>
#include <cstdlib>

#define DIVIDER 1234567

int *dp;

int solution(int n) {
	int answer = 0;

	dp = (int*)malloc(sizeof(int) * (n + 1));

	dp[1] = 1;
	dp[2] = 2;

	for(int i = 3; i <= n; i++) {
		dp[i] = ((dp[i - 2] % DIVIDER) + (dp[i - 1] % DIVIDER)) % DIVIDER; //% 1234567;
	}

	answer = dp[n];

	free(dp);

	return answer;
}

int main() {
	int n = 0;

	scanf("%d", &n);
	printf("%d\n", solution(n));

	printf("%d\n", (1204645 + 724647) % DIVIDER);
	printf("%d\n", ((1204645 % DIVIDER) + (724647 % DIVIDER)) % DIVIDER);

	return 0;
}
