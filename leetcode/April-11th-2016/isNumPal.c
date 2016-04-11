/*
[ref.href] leetcode.com/problems/palindrome-number
"
  Determine whether an integer is a palindrome. Do this without extra space.
"
*/

int isPalindrome(int x) {
    if (x < 0) return 0;
    long long i = x;
    long long m = 1;
    while (m * 10 < i) {
        m *= 10;
    }    
    while (i > 0) {
        if (i / m == i % 10) {
            i = (i - i / m * m) / 10;
            m = m / 100;
        }
        else return 0;
    }
    return 1;
}
