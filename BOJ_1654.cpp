/**
 * https://www.acmicpc.net/problem/1654
 */

#include <cstdio>
#include <climits>
#include <vector>

using std::vector;

vector<long long> cable;

long long result = 0;
long long begin = 0;
long long end = LLONG_MAX;

int main() {
    int K, N;

    scanf("%d %d", &K, &N);

    for (int i = 0; i < K; i++) {
        long long value;

        scanf("%lld", &value);

        cable.push_back(value);
    }

    while (begin <= end) {
        long long sum = 0;
        long long middle = (begin + end) / 2;

        for (int i = 0; i < K; i++) {
            sum += cable[i] / middle;
        }

        if (sum >= N) {
            begin = middle + 1;

            if (middle > result) {
                result = middle;
            }
        }
        else {
            end = middle - 1;
        }
    }

    printf("%lld\n", result);

    return 0;
}
