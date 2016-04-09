"""
  [ref.href] leetcode.com/problems/roman-to-integer
  
  "
    Given a roman numeral, convert it to an integer.
    
    Input is guaranteed to be within the range from 1 to 3999.
  "
"""

#include <limits.h>
#include <string.h>
#include <ctype.h>

static int ROMAN_TABLE[UCHAR_MAX];

#define INIT_ROMAN_TABLE() \
    do { ROMAN_TABLE['I'] = 1; ROMAN_TABLE['V'] = 5; \
         ROMAN_TABLE['X'] = 10; ROMAN_TABLE['L'] = 50; \
         ROMAN_TABLE['C'] = 100; ROMAN_TABLE['D'] = 500; \
         ROMAN_TABLE['M'] = 1000; } while (0)

int romanToInt(const char* s) {
    
    INIT_ROMAN_TABLE();
        
    if (!s) return 0;

    int len = (int)strlen(s);

    int value = 0;
    int currval = 0; int next = 0;

    int i = 0, j = 0; 
    unsigned char c = '\0';

    while (i < len) 
    {
        c = toupper(s[i]);
        currval = ROMAN_TABLE[c];
        if (!currval) {
            return 0;
        }
        if (i == len - 1) {
            next = currval;
        } else {
            next = ROMAN_TABLE[toupper(s[i + 1])];
        }
        value += currval;
        if (currval < next) {
            j = i + 1;
            while (j > 0 
                    && currval < next
                    && currval >= ROMAN_TABLE[toupper(s[j - 1])])
            {
                currval = ROMAN_TABLE[toupper(s[j - 1])];
                value -= currval * 2;
                --j;
            }            
        }
        ++i;
    }
    return value;
}
