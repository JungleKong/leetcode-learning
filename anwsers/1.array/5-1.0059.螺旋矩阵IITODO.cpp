#include "../../include/utils.h"


vector<vector<int>> generateMatrix(int n) {
    if (n == 1) return {{1}};
    vector<vector<int>> res(n, vector<int>(n));

    // 统一坚持左闭右开, 上闭下开
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    for (int i = 1; i <= n * n;) {
        int j = left;
        while (j < right) {
            res[top][j] = i;
            i++;j++;
        }
        
        j = top;
        while (j < bottom) {
            res[j][right] = i;
            i++;j++;
        }

        j = right;
        while (j > left) {
            res[bottom][j] = i;
            i++;j--;
        }

        j = bottom;
        while (j > top) {
            res[j][left] = i;
            i++;j--;
        }

        top++;
        right--;
        bottom--;
        left++;
        if (right == left && bottom == top) {
            res[left][top] = i;
            i++;
        }
    }
    return res;
}

// 左闭右闭,上闭下闭
vector<vector<int>> generateMatrix(int n) {
    
}

int main() {
    generateMatrix(1);
    return 0;
}