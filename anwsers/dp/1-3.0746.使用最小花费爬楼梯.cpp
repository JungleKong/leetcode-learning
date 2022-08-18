#include "../../include/utils.h"

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        // 到达第i个台阶所花费的最少体力为f[i]
        vector<int> f(cost.size());
        f[0] = cost[0];
        f[1] = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            f[i] = min(f[i - 1], f[i - 2]) + cost[i];
        }
        return min(f[cost.size() - 1], f[cost.size() - 2]);
    }
};