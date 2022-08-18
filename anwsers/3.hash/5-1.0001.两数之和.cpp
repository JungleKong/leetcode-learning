#include "../../include/utils.h"

vector<int> twoSum(vector<int>& nums, int target) {
    // 不能使用set, 要记录下标
    // unordered_set<int> set(nums.begin(), nums.end());

    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        map[nums[i]] = i;  // 重复应该没关系吧
    }
    for (int i = 0; i < nums.size(); i++) {
        auto iter = map.find(target - nums[i]);
        if (iter != map.end() && (iter->second != i)) {
            return {i, iter->second};
        }
    }
    return {0, 1};
}