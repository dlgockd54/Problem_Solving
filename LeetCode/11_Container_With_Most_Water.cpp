#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int size = height.size();
        int answer = 0;

        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                int beginHeight = height[i];
                int endHeight = height[j];
                int area = beginHeight < endHeight ? beginHeight * (j - i) : endHeight * (j - i);

                answer = answer > area ? answer : area;
            }
        }

        return answer;
    }
};

int main() {
    Solution *sol = new Solution();
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    printf("%d\n", sol->maxArea(height));

    height = {2, 8};

    printf("%d\n", sol->maxArea(height));

    delete sol;

    return 0;
}