#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> answer;
        int index = -1;
        int lowestIdx = -1;
        int biggestIdx = -1;
        int size = nums.size();
        int begin = 0;
        int end = size - 1;

        while (begin <= end) {
            int middle = (begin + end) / 2;

            if (target < nums[middle]) {
                end = middle - 1;
            } else if (target > nums[middle]) {
                begin = middle + 1;
            } else {
                index = middle;

                break;
            }
        }

        if (index > -1) {
            lowestIdx = index;
            biggestIdx = index;

            for (int i = index - 1; i > -1 && nums[i] == target; i--) {
                lowestIdx = i;
            }

            for (int i = index + 1; i < size && nums[i] == target; i++) {
                biggestIdx = i;
            }
        }

        answer.push_back(lowestIdx);
        answer.push_back(biggestIdx);

        return answer;
    }
};

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> result;
    int target = 8;
    Solution *sol = new Solution();

    result = sol->searchRange(nums, target);

    printf("%d, %d\n", result[0], result[1]);


    nums = {5, 7, 7, 8, 8, 10};
    target = 6;
    result = sol->searchRange(nums, target);

    printf("%d, %d\n", result[0], result[1]);

    delete sol;

    return 0;
}