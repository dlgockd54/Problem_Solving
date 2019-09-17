#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int size = nums.size();
        int numOfOne = 0;
        int numOfTwo = 0;
        int idx = size - 1;
        vector<int> zeroArr(size, 0);

        for (int i = 0; i < size; i++) {
            if (nums[i] == 1) {
                numOfOne++;
            } else if (nums[i] == 2) {
                numOfTwo++;
            }
        }

        nums.swap(zeroArr);

        while (numOfOne > 0 || numOfTwo > 0) {
            if (numOfTwo > 0) {
                nums[idx] = 2;
                numOfTwo--;
            } else {
                nums[idx] = 1;
                numOfOne--;
            }

            idx--;
        }
    }
};

int main() {
    Solution *sol;
    vector<int> nums;

    sol = new Solution();
    nums = {2, 0, 2, 1, 1, 0};
    sol->sortColors(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    delete sol;

    return 0;
}