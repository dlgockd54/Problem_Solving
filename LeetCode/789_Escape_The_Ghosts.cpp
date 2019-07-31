#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int getDistanceToTarget(vector<int>& target, vector<int>& position) {
		return abs(position[0] - target[0]) + abs(position[1] - target[1]);
	}

    bool escapeGhosts(vector< vector<int> >& ghosts, vector<int>& target) {
		vector<int> player = { 0, 0 };
		int numOfGhost = ghosts.size();
		int playerDistance = getDistanceToTarget(target, player);

		for(int i = 0; i < numOfGhost; i++) {
			int ghostDistance = getDistanceToTarget(target, ghosts[i]);

            if(ghostDistance <= playerDistance) {
                return false;
            }
		}

		return true;
    }
};

int main() {
	Solution sol = Solution();
	vector< vector<int> > ghosts = {
		{0,3},
		{1,0}
	};
	vector<int> target = {0,1};

	ghosts = {
		{2,0}
	};
	target = {1, 0};

    ghosts = {
		{1, 0}
	};
	target = {2,0};

	if(sol.escapeGhosts(ghosts, target)) {
		printf("true\n");
	} else {
		printf("false\n");
	}

	return 0;
}