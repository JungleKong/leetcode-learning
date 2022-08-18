#include "../../include/utils.h"

// 从后向前遍历,改变了元素的相对位置,不稳定
int removeElement(vector<int>& nums, int val) { 
    int len = nums.size();
    int j = len - 1;
    for (int i = len - 1; i >= 0; --i) {
        if (nums[i] == val) {
            swap(nums[i], nums[j]);
            j--;
        }
    }
    return j + 1;
}

// 从前向后遍历,
int removeElement2(vector<int>& nums, int val) { 
    int fast = 0, slow = 0;
    for (; fast < nums.size(); fast++) {
        if (nums[fast] != val) {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}

int main() {
    vector<int> nums = {0,1,2,2,3,0,4,2};
    cout << removeElement2(nums, 2) << endl;;
    printVec(nums);
    return 0;
}