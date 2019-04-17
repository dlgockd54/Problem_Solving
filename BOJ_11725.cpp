/**
 * https://www.acmicpc.net/problem/11725
 */

#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001

using namespace std;

bool isVisited[MAX];
queue< pair<int, int> > q;
vector<int> adjList[MAX];
int resultArr[MAX];

int main() {
    int N = 0;

    scanf("%d", &N);

    for(int i = 0; i < N - 1; i++) {
        int u;
        int v;

        scanf("%d %d", &u, &v);

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    isVisited[1] = true;

    q.push(make_pair(1, 0));

    for(; !q.empty(); ) {
        int child = q.front().first;
        int parent = q.front().second;

        resultArr[child] = parent;

        for(int i = 0; i < adjList[child].size(); i++) {
            int y = adjList[child][i];

            if(!isVisited[y]) {
                isVisited[y] = true;

                q.push(make_pair(y, child));
            }
        }

        q.pop();
    }

    for(int i = 2; i <= N; i++) {
        printf("%d\n", resultArr[i]);
    }

    return 0;
}
