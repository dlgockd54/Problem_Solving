#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
private:
    queue<pair<int, int>> q;
    bool **isVisited;
public:
    int numIslands(vector<vector<char>> &grid) {
        int numOfIsland = 0;

        if (!grid.empty()) {
            int row = grid.size();
            int col = grid[0].size();
            int dx[4] = {0, 0, 1, -1};
            int dy[4] = {1, -1, 0, 0};

            isVisited = new bool *[row];

            for (int i = 0; i < row; i++) {
                isVisited[i] = new bool[col];

                memset(isVisited[i], false, sizeof(bool) * col);
            }

            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (!isVisited[i][j] && grid[i][j] == '1') {
                        numOfIsland++;
                        isVisited[i][j] = true;
                        q.push(make_pair(i, j));

                        while (!q.empty()) {
                            int x = q.front().first;
                            int y = q.front().second;

                            for (int k = 0; k < 4; k++) {
                                int newX = dx[k] + x;
                                int newY = dy[k] + y;

                                if (newX > -1 && newX < row && newY > -1 && newY < col) {
                                    if (!isVisited[newX][newY] && grid[newX][newY] == '1') {
                                        isVisited[newX][newY] = true;
                                        q.push(make_pair(newX, newY));
                                    }
                                }
                            }

                            q.pop();
                        }
                    }
                }
            }

            for (int i = 0; i < row; i++) {
                delete[] isVisited[i];
            }

            delete[] isVisited;
        }

        return numOfIsland;
    }
};

int main() {
    Solution *sol;
    vector<vector<char>> grid;

    sol = new Solution();
    grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'}
    };
    cout << sol->numIslands(grid) << endl;
    delete sol;

    sol = new Solution();
    grid = {};
    cout << sol->numIslands(grid) << endl;
    delete sol;

    return 0;
}