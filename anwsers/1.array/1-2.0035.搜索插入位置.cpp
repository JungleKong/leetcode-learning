#include "../../include/utils.h"

// 暴力解法
int searchInsert(vector<int>& nums, int target) {
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] >= target) {
            return i;
        } 
    }
    return nums.size();
}

int searchInsert2(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target == nums[mid]) { return mid; }
        else if (target < nums[mid]) { right = mid - 1; }
        else if (target > nums[mid]) { left = mid + 1; }
    }
    // 没有找到相等的元素
    return right + 1;
}

int searchInsert3(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (target == nums[mid]) return mid;
        else if (target < nums[mid]) right = mid;
        else if (target > nums.at(mid)) left = mid + 1;
    }
    // 没有找到相等的元素
    return right;
}

int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    cout << searchInsert3(nums, -2) << endl;
    return 0;
}
