/**
 * https://www.acmicpc.net/problem/1697
 */

#include <iostream>
#include <queue>

#define MAX 100001

using namespace std;

queue< pair<int, int> > q;
bool isVisited[MAX];

int solution(int N, int K) {
    int ret = 0;

    if(N != K) {
        isVisited[N] = true;

        q.push(make_pair(N, 0));

        for(; !q.empty();) {
            int x = q.front().first;
            int seconds = q.front().second;
            int newXArr[3] = { x - 1, x + 1, x * 2 };

            q.pop();

            for(int i = 0; i < 3; i++) {
                if(newXArr[i] == K) {
                    return seconds + 1;
                }

                if(newXArr[i] >= 0 && newXArr[i] < MAX) {
                    if(!isVisited[newXArr[i]]) {
                        q.push(make_pair(newXArr[i], seconds + 1));
                    }
                }
            }
        }
    }

    return ret;
}

int main() {
    int N = 0;
    int K = 0;

    scanf("%d %d", &N, &K);

    printf("%d\n", solution(N, K));

    return 0;
}
