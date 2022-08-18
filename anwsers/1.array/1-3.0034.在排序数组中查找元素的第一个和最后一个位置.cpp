#include "../../include/utils.h"

// 找寻右边界, 不包含右边界的右边界
int findRightBorder(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int rightBorder = -2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target < nums.at(mid)) right = mid - 1;
        else if (target >= nums.at(mid)) {
            left = mid + 1;
            rightBorder = left;
        }
    }
    return rightBorder;
}

// 找寻左边界, 不包含左边界的左边界
int findLeftBorder(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int leftBorder = -2;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (target > nums.at(mid)) left = mid + 1;
        else if (target <= nums.at(mid)) {
            right = mid - 1;
            leftBorder = right;
        }
    }
    return leftBorder;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int leftBorder = findLeftBorder(nums, target);
    int rightBorder = findRightBorder(nums, target);
    if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
    if (leftBorder + 1 == rightBorder) return {-1, -1};
    return {leftBorder + 1, rightBorder - 1};
}



int main() {
    vector<int> nums = {5,7,7,8,8,10};
    cout << findLeftBorder(nums, 10) << endl;
    cout << findRightBorder(nums, 10) << endl;
    return 0;
}