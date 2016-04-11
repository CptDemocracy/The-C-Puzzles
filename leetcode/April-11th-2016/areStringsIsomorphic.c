/*
[ref.href] leetcode.com/problems/isomorphic-strings
"
  Given two strings s and t, determine if they are isomorphic.

  Two strings are isomorphic if the characters in s can be replaced to get t.
  
  All occurrences of a character must be replaced with another character while 
  preserving the order of characters. No two characters may map to the same 
  character but a character may map to itself.
  
  For example,
  Given "egg", "add", return true.
  Given "foo", "bar", return false.
  Given "paper", "title", return true.
  
  Note:
  You may assume both s and t have the same length.
"
*/

#include <limits.h>

/*
  PLEASE NOTICE.
  For the love of ALGOL, don't write production code like the one you see below.
  Honestly, I had my "1337 hax0r skillz"-hat one when I was writing this code.
*/

int isIsomorphic(char* s, char* t) {
    int keys[CHAR_MAX] = { 0 };
    int vals[CHAR_MAX] = { 0 };
    char a = '\0', b = '\0', m = '\0';
    while ((a = *s) && (b = *t)) {
        if (((m = keys[a]) && m != b) 
         || ((m = vals[b]) && m != a)) return 0;
        keys[a] = b;
        vals[b] = a;
        ++s; ++t;
    }
    return 1;
}
