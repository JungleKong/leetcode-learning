#include "../../include/utils.h"

// hash去重太复杂了,放弃
vector<vector<int>> threeSum(vector<int>& nums) {
    unordered_map<int, int> map;
    for (int a: nums) {
        map[a]++;
    }
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            if (i == j) continue;
            int b = nums[i], c = nums[j];
            int a = 0 - b - c;
            if (map.find(a) != map.end()) {
                res.push_back({a, b, c});
                map[a]--;
                if (map[a] == 0) {
                    map.erase(a);
                }
            }
        }
    }
    return res;
}

// 双指针
vector<vector<int>> threeSum(vector<int>& nums) {
    // 先排序
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) break;

        // 去重a
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            if (nums[i] + nums[left] + nums[right] < 0) left++;
            else if (nums[i] + nums[left] + nums[right] > 0) right--;
            else {
                res.push_back({nums[i], nums[left], nums[right]});

                // 去重b
                while (left < right && nums[right] == nums[right - 1]) right--;
                // 去重c
                while (left < right && nums[left] == nums[left + 1]) left++;

                // 找到答案
                left++;
                right--;
            }
        }
    }
    return res;
}