#include "../../include/utils.h"

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int bagSize = sum / 2;
        vector<int> weight = stones;
        vector<int> value = stones;

        vector<int> dp(bagSize + 1, 0);
        for (int i = 0; i < weight.size(); i++) {
            for (int j = bagSize; j>= weight[i]; j--) {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        return abs(sum - dp[bagSize] - dp[bagSize]);
    }
};


int main() {
    vector<int> stones = {31, 26, 33, 21, 40};
    Solution so;
    cout << so.lastStoneWeightII(stones) << endl;
    return 0;
}