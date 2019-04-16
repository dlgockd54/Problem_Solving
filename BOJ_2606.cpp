/**
 * https://www.acmicpc.net/problem/2606
 */

#include <iostream>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

vector<int> adjList[MAX];
bool isVisited[MAX];
queue<int> q;

int main() {
    int numOfComputer = 0;
    int numOfConnection = 0;
    int result = 0;

    scanf("%d %d", &numOfComputer, &numOfConnection);

    for(int i = 0; i < numOfConnection; i++) {
        int u;
        int v;

        scanf("%d %d", &u, &v);

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    isVisited[1] = true;

    q.push(1);

    for(; !q.empty();) {
        int x = q.front();

        q.pop();

        for(int i = 0; i < adjList[x].size(); i++) {
            int y = adjList[x][i];

            if(!isVisited[y]) {
                result++;
                isVisited[y] = true;

                q.push(y);
            }
        }
    }

    printf("%d\n", result);

    return 0;
}