#include "../../include/utils.h"

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int bagSize = sum / k;

        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> buckets(k);
        return backtracking(0, k, nums, buckets, bagSize);
    }

    bool backtracking(int index, int k, vector<int>& nums, vector<int>& buckets, int bagSize) {
        if (index >= nums.size()) {
            return true;
        }

        for (int i = 0; i < k; i++) {
            if (i > 0 && buckets[i] == buckets[i - 1]) continue;  // 如果当前桶和上一个桶的元素相同, 等效
            buckets[i] += nums[index];
            if (buckets[i] <= bagSize && backtracking(index + 1, k, nums, buckets, bagSize)) {
                return true;
            }
            if (i > 0 && index == 0) break;  // 第一个元素放在哪一个桶都是等效的
            buckets[i] -= nums[index];
        }
        return false;
    }
};

int main() {
    vector<int> nums = {4,3,2,3,5,2,1};
    Solution so;
    cout << so.canPartitionKSubsets(nums, 4) << endl;
    return 0;
}