#include "../../include/utils.h"


// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]
// 解释：
// 滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

// 使用单调递减队列
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int len = nums.size();
    vector<int> res;
    deque<int> que;
    int max = INT_MIN;
    for (int i = 0; i < k; i++) {
        while (!que.empty() && que.back() < nums[i]) {
            que.pop_back();
        }
        que.push_back(nums[i]);
    }
    res.push_back(que.front());

    for (int i = k; i < nums.size(); i++) {
        // pop
        if (!que.empty() && nums[i - k] == que.front()) {
            que.pop_front();
        }

        // push
        while (!que.empty() && que.back() < nums[i]) {
            que.pop_back();
        }
        que.push_back(nums[i]);

        res.push_back(que.front());
    }
    return res;
}   

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    printVec(maxSlidingWindow(nums, 3));
    return 0;
}