#include "../../include/utils.h"

int minSubArrayLen(int target, vector<int>& nums) {
    if (accumulate(nums.begin(), nums.end(), 0) < target) return 0;
    int len = nums.size();
    int i = 0, j = 0, sum = 0;
    int res = nums.size();
    for (; j < len; ++j) {
        sum += nums.at(j);
        while (sum >= target) {
            res = min(j - i + 1, res);
            sum -= nums.at(i);
            i++;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    cout << minSubArrayLen(7, nums) << endl;
    return 0;
}