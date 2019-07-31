/**
 * You are playing a simplified Pacman game. You start at the point (0, 0),
 * and your destination is (target[0], target[1]). There are several
 * ghosts on the map, the i-th ghost starts at (ghosts[i][0], ghosts[i][1]).
 * 
 * Each turn, you and all ghosts simultaneously *may* move in one of 4
 * cardinal directions: north, east, west, or south, going from the previous
 * point to a new point 1 unit of distance away.
 * 
 * You escape if and only if you can reach the target before any ghost reaches you (for any given moves the ghosts may take.)  If you reach any square (including the target) at the same time as a ghost, it doesn't count as an escape.
 * 
 * Return True if and only if it is possible to escape.
 */

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