#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> backtrack(vector<int> nums) {
        vector<vector<int>> ret;

        if (nums.size() == 0) {
            ret.push_back({});
        } else {
            vector<int> deletedArr(nums);
            vector<vector<int>> returnedArr;
            int size = 0;

            deletedArr.pop_back();
            returnedArr = backtrack(deletedArr);
            size = returnedArr.size();

            for (int i = 0; i < size; i++) {
                if (find(ret.begin(), ret.end(), returnedArr[i]) == ret.end()) {
                    ret.push_back(returnedArr[i]);
                }

                returnedArr[i].push_back(nums[nums.size() - 1]);

                if (find(ret.begin(), ret.end(), returnedArr[i]) == ret.end()) {
                    ret.push_back(returnedArr[i]);
                }
            }
        }

        return ret;
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int> > answer = backtrack(nums);

        return answer;
    }
};

int main() {
    Solution *sol = new Solution();
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol->subsets(nums);

    for (int i = 0; i < result.size(); i++) {
        int size = result[i].size();

        for (int j = 0; j < size; j++) {
            printf("%d ", result[i][j]);
        }

        printf("\n");
    }

    nums = {1, 2, 3, 3};
    result = sol->subsets(nums);

    for (int i = 0; i < result.size(); i++) {
        int size = result[i].size();

        for (int j = 0; j < size; j++) {
            printf("%d ", result[i][j]);
        }

        printf("\n");
    }

    return 0;
}