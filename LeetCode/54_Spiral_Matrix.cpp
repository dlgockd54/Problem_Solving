#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

enum Direction {
    EAST, SOUTH, WEST, NORTH
};

class Solution {
private:
    bool **isVisited;
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;

        if (!matrix.empty()) {
            int row = matrix.size();
            int col = matrix[0].size();
            int direction = EAST;
            int numOfRemainElement = row * col;
            int dx[4] = {0, 1, 0, -1};
            int dy[4] = {1, 0, -1, 0};

            isVisited = new bool *[row];

            for (int i = 0; i < row; i++) {
                isVisited[i] = new bool[col];

                memset(isVisited[i], false, sizeof(bool) * col);
            }

            for (int x = 0, y = 0;;) {
                int newX = dx[direction] + x;
                int newY = dy[direction] + y;

                isVisited[x][y] = true;
                numOfRemainElement--;
                result.push_back(matrix[x][y]);

                if (!(newX > -1 && newX < row && newY > -1 && newY < col) || isVisited[newX][newY]) {
                    direction = direction < 3 ? direction + 1 : 0;

                    newX = dx[direction] + x;
                    newY = dy[direction] + y;
                }

                x = newX;
                y = newY;

                if (numOfRemainElement <= 0) {
                    break;
                }
            }

            for (int i = 0; i < row; i++) {
                delete[] isVisited[i];
            }

            delete[] isVisited;
        }

        return result;
    }
};

int main() {
    Solution *sol;
    vector<vector<int>> matrix;
    vector<int> result;

    sol = new Solution();
    matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    result = sol->spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;
    delete sol;

    sol = new Solution();
    matrix = {
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12}
    };
    result = sol->spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;
    delete sol;

    sol = new Solution();
    matrix = {};
    result = sol->spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;
    delete sol;

    sol = new Solution();
    matrix = {
            {1}
    };
    result = sol->spiralOrder(matrix);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;
    delete sol;

    return 0;
}