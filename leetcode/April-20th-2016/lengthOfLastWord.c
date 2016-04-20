/*
[ref.href] leetcode.com/problems/length-of-last-word
"
  Given a string s consists of upper/lower-case alphabets and empty 
  space characters ' ', return the length of last word in the string.

  If the last word does not exist, return 0.
  
  Note: A word is defined as a character sequence consists of non-space 
  characters only.
  
  For example, 
  Given s = "Hello World",
  return 5.
"
*/

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int lengthOfLastWord(char* s) {
    // no string, return 0
    if (!s) {
        return 0;
    }
    
    // .init section
    size_t len = 0;
    char   *pc = &s[strlen(s)];
    
    // skip whitespace at the end
    while (pc > s && isspace(*(pc - 1))) --pc;
    
    // count the number of characters
    while (pc > s && !isspace(*(pc - 1))) --pc, ++len;
    
    return len;
}
