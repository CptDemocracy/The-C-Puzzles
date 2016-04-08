/*
[ref.href] leetcode.com/problems/string-to-integer-atoi
"
  Implement atoi to convert a string to an integer.
  
  Hint: Carefully consider all possible input cases. If you want a
  challenge, please do not see below and ask yourself what are the 
  possible input cases.
  
  Notes: It is intended for this problem to be specified vaguely 
  (ie, no given input specs). You are responsible to gather all the 
  input requirements up front.
"

*/

#include <ctype.h>

int myAtoi(char* str) {
    char* pchar = str;
    while (isspace(*pchar)) ++pchar;
    if (!*pchar) return 0;
    
    int sign = 1;
    
    if (*pchar == '+') {
        ++pchar;
    }
    else if (*pchar == '-') {
        sign = -1;
        ++pchar;
    }
    
    long long int value = 0LL;
    
    while (isdigit(*pchar)) {
        value = value * 10LL + (*pchar - '0');
        if (sign > 0 && value > INT_MAX) {
            return INT_MAX;
        }
        else if (sign < 0 && -value < INT_MIN) {
            return INT_MIN;
        }
        ++pchar;
    }
    
    return (int)value * sign;
}
