/*
[ref.href] leetcode.com/problems/happy-number

"
    Write an algorithm to determine if a number is "happy".
    
    A happy number is a number defined by the following process: 
    Starting with any positive integer, replace the number by 
    the sum of the squares of its digits, and repeat the process 
    until the number equals 1 (where it will stay), or it loops 
    endlessly in a cycle which does not include 1. Those numbers 
    for which this process ends in 1 are happy numbers.
    
    Example: 19 is a happy number
    
    12 + 92 = 82
    82 + 22 = 68
    62 + 82 = 100
    12 + 02 + 02 = 1
    
    Credits:
    Special thanks to @mithmatt and @ts for adding this problem and creating all test cases.
"
*/

int isHappy(int n) 
{
    if (n < 1) {
        return 0;
    }
    int m = n;
    int msum = 0;
    int nsum = 0;
    do {
        nsum = 0;
        while (n > 0) {
            nsum += (n % 10) * (n % 10);
            n /= 10;
        }
        n = nsum;
        if (n == 1) return 1;

        for (int i = 0; i < 2; ++i) {
            msum = 0;
            while (m > 0) {
                msum += (m % 10) * (m % 10);
                m /= 10;
            }
            m = msum;
        }
        if (n == m) break;
    } while (1);

    return 0;
}
