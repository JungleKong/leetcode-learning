#include "../../include/utils.h"

bool isPerfectSquare(int num) {
    if (num == 1) return true;
    int left = 0, right = num;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;
        if (num == square) return true;
        else if (num < square) right = mid - 1;
        else if (num > square) left = mid + 1;
    }
    return false;
}

int main() {
    cout << isPerfectSquare(9) << endl;
    return 0;
}