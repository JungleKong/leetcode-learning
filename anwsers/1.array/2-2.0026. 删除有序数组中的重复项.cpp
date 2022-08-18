#include "../../include/utils.h"

int removeDuplicates(vector<int>& nums) {
    int slow = 0, fast = 1;
    for (; fast < nums.size(); ++fast) {
        if (nums[fast] != nums[slow]) {
            nums[++slow] = nums[fast];
        }
    } 
    return slow + 1;
}

int main() {
    vector<int> nums = {1,1,2,2,3,3,3,4,5};
    cout << removeDuplicates(nums) << endl;;
    printVec(nums);
    return 0;
}