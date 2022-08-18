#include "../../include/utils.h"

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        printVec(dp);
        return dp[n];
    }
};

int main() {
    Solution so;
    cout << so.integerBreak(10) << endl;
    return 0;
}