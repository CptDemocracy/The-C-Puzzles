/*
[ref.href] leetcode.com/problems/valid-anagram
"
  Given two strings s and t, write a function to determine if 
  t is an anagram of s.
  
  For example,
  s = "anagram", t = "nagaram", return true.
  s = "rat", t = "car", return false.
  
  Note:
  You may assume the string contains only lowercase alphabets.
"
*/

#include <limits.h>

bool isAnagram(char* s, char* t) {
    int htable[UCHAR_MAX] = { 0 };
    if (strlen(s) != strlen(t)) {
        return 0;
    }
    unsigned char uc = '\0';
    while ((uc = *s) != '\0') {
        ++htable[uc]; ++s;
    }
    while ((uc = *t) != '\0') {
        if (htable[uc] < 1) {
            return 0;
        }
        --htable[uc]; ++t;
    }
    return 1;
}
