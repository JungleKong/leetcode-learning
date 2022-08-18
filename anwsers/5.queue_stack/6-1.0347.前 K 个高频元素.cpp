#include "../../include/utils.h"

// 小顶堆, 队列里只保存最大的k个值
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> maps;
    for (int i = 0; i < nums.size(); i++) {
        maps[nums[i]]++;
    }
    struct cmp
    {
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (auto& map: maps) {
        pq.emplace(map);
        if (pq.size() > k) {
            pq.pop();
        }
    } 

    vector<int> res(k);
    for (int i = k - 1; i>= 0; i--) {
        auto p = pq.top();
        res[i] = p.first;
        pq.pop();
    }
    return res;
}

// 大顶堆, 保存所有的, 返回值只取前k个
vector<int> topKFrequent2(vector<int>& nums, int k){
    unordered_map<int, int> maps;
    for (int i = 0; i < nums.size(); i++) {
        maps[nums[i]]++;
    }
    struct cmp
    {
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second < rhs.second;
        }
    };
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    for (auto& map: maps) {
        pq.emplace(map);
    } 

    vector<int> res(k);
    for (int i = k - 1; i >= 0; i--) {
        auto p = pq.top();
        res[i] = p.first;
        pq.pop();
    }
    return res;
}

int main() {
    // vector<int> nums = {3,0,1,0};
    vector<int> nums = {1,2,3,1,1,2};
    printVec(topKFrequent2(nums, 2));
    return 0;
}