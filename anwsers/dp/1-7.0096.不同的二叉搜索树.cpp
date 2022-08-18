#include "../../include/utils.h"

class Solution {
public:
    // 以某个节点为根结点的树形态数 = 左子树的形态数量 * 右子树的形态数量
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;  // 有时候0是为了数学上抽象激素方便
        dp[1] = 1;
        // dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};