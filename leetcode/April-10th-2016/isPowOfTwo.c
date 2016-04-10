/*
[ref.href] leetcode.com/problems/power-of-two
"
  Given an integer, write a function to determine if it is a power of two.
  
  Credits:
  Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
"
*/

#include <math.h>

#define EPS 1e-15

bool isPowerOfTwo(int n) {
    return fmod(log2(n), 1.0) <= EPS;
}
