/*
[ref.href] leetcode.com/problems/add-digits

"
  Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
  
  For example:
  
  Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
  
  Credits:
  Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
"
*/

int addDigits(int num) {
    int sum = 0;
    do {
        sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    } while (sum > 9);
    return num;
}
