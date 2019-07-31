/**
 * We have a two dimensional matrix A where each value is 0 or 1.
 * 
 * A move consists of choosing any row or column, and toggling each value in
 * that row or column: changing all 0s to 1s, and all 1s to 0s.
 * 
 * After making any number of moves, every row of this matrix is interpreted as
 * a binary number, and the score of the matrix is the sum of these numbers.
 * 
 * Return the highest possible score.
 * 
 * Note:
 * 1 <= A.length <= 20
 * 1 <= A[0].length <= 20
 * A[i][j] is 0 or 1.
 * 
 * Example 1:
 * Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
 * Output: 39
 * Explanation:
 * Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
 * 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    // void printArr(vector< vector<int> >& A) {
    //     int row = A.size();
    //     int col = A[0].size();

    //     for(int i = 0; i < row; i++) {
    //         for(int j = 0; j < col; j++) {
    //             printf("%d", A[i][j]);
    //         }

    //         printf("\n");
    //     }
    // }

    void flipCol(vector< vector<int> >& A, int col) {
        int row = A.size();

        for(int i = 0; i < row; i++) {
            A[i][col] = A[i][col] == 1 ? 0 : 1;
        }
    }

    int getDecimalNum(vector<int>& arr) {
        int num = 0;
        int size = arr.size();

        for(int i = 0; i < size; i++) {
            if(arr[i] == 1) {
                num = num + pow(2, size - 1 - i);
            }
        }

        return num;
    }

    int matrixScore(vector< vector<int> >& A) {
        int row = A.size();
        int col = A[0].size();
        int answer = 0;

        for(int i = 0, numOfOne = 0; i < col; i++) {
            for(int j = 0; j < row; j++) {
                if(A[j][i] == 1) {
                    numOfOne++;
                }
            }

            if(numOfOne <= row / 2) {
                flipCol(A, i);
            }

            numOfOne = 0;
        }

        for(int i = 0; i < row; i++) {
            vector<int> originRow;
            vector<int> reversedRow;
            int originNum = 0;
            int reversedNum = 0;

            for(int j = 0; j < col; j++) {
                originRow.push_back(A[i][j]);

                if(A[i][j] == 1) {
                    reversedRow.push_back(0);
                } else {
                    reversedRow.push_back(1);
                }
            }

            originNum = getDecimalNum(originRow);
            reversedNum = getDecimalNum(reversedRow);

            if(originNum < reversedNum) {
                A[i] = reversedRow;
            }
        }

        for(int i = 0, numOfOne = 0; i < col; i++) {
            for(int j = 0; j < row; j++) {
                if(A[j][i] == 1) {
                    numOfOne++;
                }
            }

            if(numOfOne <= row / 2) {
                flipCol(A, i);
            }

            numOfOne = 0;
        }

        for(int i = 0; i < row; i++) {
            answer += getDecimalNum(A[i]);
        }

        return answer;
    }
};

int main() {
    vector< vector<int> > A = {
        {0,0,1,1},
        {1,0,1,0},
        {1,1,0,0}
    };

    printf("%d\n", Solution().matrixScore(A));

    return 0;
}