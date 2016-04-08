/*
[ref.href] leetcode.com/problems/reverse-integer
"
  Reverse digits of an integer.
  
  Example1: x = 123, return 321
  Example2: x = -123, return -321
"
*/

int reverse(int x) {
    if (x == INT_MIN) {
        return 0;
    }
    long long res = 0LL;
    do {
        res = res * 10LL + x % 10;
        if (llabs(res) > INT_MAX) {
            return 0;
        }
        x /= 10;
    } while (abs(x) > 0);
    return (int)res;
}
