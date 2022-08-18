#include "../../include/utils.h"

// 左闭右开,上闭下开
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.size() == 1) return matrix[0];
    int m = matrix.size(), n = matrix[0].size();
    vector<int> res(m * n);

    int left = 0, right = n - 1, top = 0, bottom = m - 1;
    int i = 0, j = 0;
    while (i < m * n) {
        j = left;
        while (j < right) {
            res[i] = matrix[top][j];
            i++;j++;
        }

        j = top;
        while (j < bottom) {
            res[i] = matrix[j][right];
            i++;j++;
        }

        j = right;
        while (j > left) {
            res[i] = matrix[bottom][j];
            i++;j--;
        }

        j = bottom;
        while (j > top) {
            res[i] = matrix[j][left];
            i++;j--;
        }

        left++;
        right--;
        bottom--;
        top++;
        if (left == right && bottom == top) {
            res[i] = matrix[left][top];
            i++;
        }
    }
    return res;
}

// 左闭右闭,上闭下闭
vector<int> spiralOrder(vector<vector<int>>& matrix) {
}

int main() {
    // vector<vector<int>> matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12},{13,14,15,16}};
    vector<vector<int>> matrix = {{7}, {9}, {6}};
    printVec(spiralOrder(matrix));
    return 0;
}
