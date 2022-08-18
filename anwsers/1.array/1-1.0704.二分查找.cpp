#include "../include/utils.h"

int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target == nums[mid]) return mid;
        else if (target < nums[mid]) right = mid - 1;  // 核心代码, 循环不变原则, while中左闭右闭, 这里也是
        else if (target > nums[mid]) left = mid + 1;  
    }
    return -1;
}

int binarySearch2(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (target == nums[mid]) return mid;
        else if (target < nums[mid]) right = mid;  // 核心代码, 循环不变原则, while中左闭右开, 这里也是
        else if (target > nums[mid]) left = mid + 1; 
    }
    return -1;
}

int main() {
    vector<int> nums = {-1,0,3,5,9,12};
    cout << binarySearch2(nums, 9) << endl;
    return 0;
}
