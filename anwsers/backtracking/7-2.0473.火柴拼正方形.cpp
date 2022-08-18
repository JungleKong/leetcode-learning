#include "../../include/utils.h"

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
        int bagSize = sum / 4;

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        vector<int> edges(4);
        return backtracking(0, matchsticks, edges, bagSize);
    }

    bool backtracking(int index, vector<int>& matchsticks, vector<int>& edges, int bagSize) {
        if (index >= matchsticks.size()) {
            return true;
        }

        for (int i = 0; i < edges.size(); i++) {
            edges[i] += matchsticks[index];
            if (edges[i] <= bagSize && backtracking(index + 1, matchsticks, edges, bagSize)) {
                return true;
            }
            edges[i] -= matchsticks[index];
        }
        return false;
    }
};