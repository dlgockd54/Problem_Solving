#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
private:
    bool **isVisited;
public:
    bool backtrack(int i, int j, vector<vector<char>> &board, string word, string str) {
        string tempStr = str + board[i][j];

        isVisited[i][j] = true;

        if (tempStr.compare(word) == 0) {
            return true;
        } else if (tempStr.length() < word.length() &&
                   word.substr(0, tempStr.length()) == tempStr) {
            int dx[4] = {0, 0, 1, -1};
            int dy[4] = {1, -1, 0, 0};

            for (int k = 0; k < 4; k++) {
                int newX = dx[k] + i;
                int newY = dy[k] + j;

                if (newX > -1 && newX < board.size()) {
                    if (newY > -1 && newY < board[0].size()) {
                        if (!isVisited[newX][newY]) {
                            if (backtrack(newX, newY, board, word, tempStr)) {
                                return true;
                            }
                        }
                    }
                }
            }
        }

        isVisited[i][j] = false;

        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        bool answer = false;
        char firstChar = word[0];
        int row = board.size();
        int col = board[0].size();

        isVisited = new bool *[row];

        for (int i = 0; i < row; i++) {
            isVisited[i] = new bool[col];

            memset(isVisited[i], false, sizeof(bool) * col);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == firstChar) {
                    if (backtrack(i, j, board, word, "")) {
                        return true;
                    }
                }
            }

        }

        return answer;
    }
};

int main() {
    Solution *sol;
    vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}
    };
    string word;

    sol = new Solution();
    word = "ABCCED";
    cout << sol->exist(board, word) << endl;
    delete sol;

    sol = new Solution();
    word = "SEE";
    cout << sol->exist(board, word) << endl;
    delete sol;

    sol = new Solution();
    word = "ABCB";
    cout << sol->exist(board, word) << endl;
    delete sol;

    sol = new Solution();
    board = {
            {'C', 'A', 'A'},
            {'A', 'A', 'A'},
            {'B', 'C', 'D'}
    };
    word = "AAB";
    cout << sol->exist(board, word) << endl;
    delete sol;

    return 0;
}