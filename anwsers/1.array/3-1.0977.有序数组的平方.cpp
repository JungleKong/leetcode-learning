#include "../../include/utils.h"


// 从最小向最大遍历
vector<int> sortedSquares(vector<int>& nums) {
    vector<int> temp(nums.size());
    int min = INT_MAX, index = -1;
    for (int i = 0; i < nums.size(); ++i) {
        int square = nums[i] * nums[i];
        temp.at(i) = square;
        if (square < min) {
            min = square;
            index = i;
        }
    }
    int left = index - 1, right = index + 1;
    vector<int> res(nums.size());
    int i = 0;
    res.at(i++) = temp.at(index);
    while (left >= 0 && right < nums.size()) {
        if (temp.at(left) < temp.at(right)) {
            res.at(i++) = temp.at(left--);
        } else {
            res.at(i++) = temp.at(right++);
        }
    }
    while (left >= 0) res.at(i++) = temp.at(left--);
    while (right < nums.size()) res.at(i++) = temp.at(right++);
    return res;
}

// 从最大向最小遍历
vector<int> sortedSquares2(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    int i = nums.size() - 1;
    vector<int> res(nums.size());
    while (left <= right) {
        if (nums[left] * nums[left] < nums[right] * nums[right]) {
            res[i--] = nums[right] * nums[right];
            right--;
        } else {
            res[i--] = nums[left] * nums[left];
            left++;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {-7,-3,2,3,11};
    printVec(sortedSquares2(nums));
    return 0;
}