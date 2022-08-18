#include "../../include/utils.h"

class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        vector<int> f(n + 1);
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }

    int fib(int n) {
        if (n < 2) return n;
        int a = 0, b = 1;
        int res = 0;
        for (int i = 2; i <= n; i++) {
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
};