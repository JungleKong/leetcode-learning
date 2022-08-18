#include "../../include/utils.h"

int mySqrt(int x) {
    if (x == 0 || x == 1) return x;
    int left = 0, right = x;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;
        if (x == square) return mid;
        else if (x < square) right = mid - 1;
        else if (x > square) left = mid + 1;
    }
    return right;
}

int main() {
    cout << mySqrt(1994) << endl;
    return 0;
}
