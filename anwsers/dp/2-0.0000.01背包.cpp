#include "../../include/utils.h"

class Solution {

public:
    int bag01(vector<int>& weight, vector<int>& value, int bagSize) {
        // dp[i][j] 表示从下标为[0-i]的物品里任意取，放进容量为j的背包，价值总和最大是多少。
        //           0       1       2       3        4
        //  物品0
        //  物品1
        //  物品2
        vector<vector<int>> dp(weight.size(), vector<int>(bagSize + 1, 0));
        for (int i = weight[0]; i < bagSize; i++) {
            dp[0][i] = value[0];
        }

        for (int i = 1; i < weight.size(); i++) {
            for (int j = 0; j <= bagSize; j++) {
                if (j < weight[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
        return dp[weight.size() - 1][bagSize];
    }

    int bag01_(vector<int>& weight, vector<int>& value, int bagSize) {
        vector<int> dp(bagSize + 1, 0);

        for (int i = 0; i < weight.size(); i++) {
            for (int j = bagSize; j >= weight[i]; j--) {
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }

        return dp[bagSize];
    }
};

int main() {
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagSize = 4;

    Solution so;
    cout << so.bag01_(weight, value, bagSize) << endl;
    return 0;
}

