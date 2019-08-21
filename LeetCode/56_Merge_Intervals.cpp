#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        queue<vector<int>> q;
        vector<vector<int>> answer;
        bool isFirstInterval = true;
        int size = intervals.size();
        int begin = 0;
        int end = 0;

        if (size > 0) {
            sort(intervals.begin(), intervals.end());

            for (int i = 0; i < size; i++) {
                q.push(intervals[i]);
            }

            while (!q.empty()) {
                vector<int> interval = q.front();

                q.pop();

                if (isFirstInterval) {
                    begin = interval[0];
                    end = interval[1];
                    isFirstInterval = false;
                } else {
                    if (interval[0] >= begin && interval[0] <= end) {
                        if(interval[1] > end) {
                            end = interval[1];
                        }
                    } else {
                        answer.push_back({begin, end});
                        begin = interval[0];
                        end = interval[1];
                    }
                }
            }

            answer.push_back({begin, end});
        }

        return answer;
    }
};

int main() {
    Solution *sol = new Solution();
    vector<vector<int>> intervals = {
            {1,  3},
            {2,  6},
            {8,  10},
            {15, 18}};
    vector<vector<int>> result = sol->merge(intervals);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << ", " << result[i][1] << endl;
    }

    intervals = {
            {1, 4},
            {4, 5}
    };
    result = sol->merge(intervals);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << ", " << result[i][1] << endl;
    }

    intervals = {};
    result = sol->merge(intervals);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << ", " << result[i][1] << endl;
    }

    intervals = {
            {1, 4},
            {2, 3}
    };
    result = sol->merge(intervals);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i][0] << ", " << result[i][1] << endl;
    }

    delete sol;

    return 0;
}