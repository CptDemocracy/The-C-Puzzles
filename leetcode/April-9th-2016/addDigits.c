/*
[ref.href] leetcode.com/problems/add-digits

"
  Given a non-negative integer num, repeatedly add all its digits 
  until the result has only one digit.
  
  For example:
  
  Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. 
  Since 2 has only one digit, return it.
  
  Credits:
  Special thanks to @jianchao.li.fighter for adding this problem 
  and creating all test cases.
"
*/

int addDigits(int num) {
    if (num < 10) {
        return num;
    }
    num = num % 10 + addDigits(num / 10);
    return addDigits(num);
}

/*
Bonus: Solution in Python 2.7

class Solution(object):
    def addDigits(self, n):
        """
        :type num: int
        :rtype: int
        """
        if n < 10:
            return n
        n = n % 10 + self.addDigits(n // 10)
        return self.addDigits(n)
*/
