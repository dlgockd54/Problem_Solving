/**
 * https://www.acmicpc.net/problem/7562
 */

#include <iostream>
#include <vector>
#include <queue>

#define MAX 300

using namespace std;

queue< pair< pair<int, int>, int> > q;

int solution() {
    int l = 0;
    int board[MAX][MAX];
    int startX = 0;
    int startY = 0;
    int endX = 0;
    int endY = 0;
    int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
    int result = 0;

    for(; !q.empty();) {
        q.pop();
    }

    scanf("%d %d %d %d %d", &l, &startX, &startY, &endX, &endY);

    if(!(startX == endX && startY == endY)) {
        for(int i = 0; i < l; i++) {
            memset(board + i, 0, sizeof(int) * l);
        }

        q.push(make_pair(make_pair(startX, startY), 0));

        board[startX][startY] = 1;

        for(; !q.empty(); ) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int count = q.front().second;
            
            for(int i = 0; i < 8; i++) {
                int newX = dx[i] + x;
                int newY = dy[i] + y;
    
                if(newX == endX && newY == endY) {
                    return count + 1;
                }
    
                if(newX >= 0 && newX < l) {
                    if(newY >= 0 && newY < l) {
                        if(board[newX][newY] < 1) {
                            board[newX][newY] = 1;
    
                            q.push(make_pair(make_pair(newX, newY), count + 1));
                        }
                    }
                }
            }
    
            q.pop();
        }
    }

    return result;
}

int main() {
    int T = 0;

    scanf("%d", &T);

    while(T--) {
        printf("%d\n", solution());
    }

    return 0;
}