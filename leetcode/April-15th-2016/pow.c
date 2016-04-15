/*
[ref.href] leetcode.com/problems/powx-n
"
  Implement pow(x, n).
"
*/

#include <math.h>
#define EPSILON (1e-6)

double myPow(double x, int n) {
    if (n == 0) {
        return 1;
    }
    if (n == -n) {
        // guard against power==INT_MIN shenanigans
        x = fabs(x);
        if (fabs(x - 1) <= EPSILON) {
            return x;
        }
        return 0.0;
    }
    if (n < 0) {
        x = 1.0 / x;
        n = -n;
    }
    double y = 1.0;
    while (n > 1) {
        if (n % 2 == 0) {
            x *= x;
            n >>= 1;
        }
        else {
            y *= x;
            x *= x;
            n = (n - 1) >> 1;
        }
    }
    return x * y;
}
