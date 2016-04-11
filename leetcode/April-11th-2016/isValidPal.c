/*
[ref.href] leetcode.com/problems/valid-palindrome
"
    Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
    
    For example,
    "A man, a plan, a canal: Panama" is a palindrome.
    "race a car" is not a palindrome.
"
*/

#include <string.h>

/* 
    I'll be frank, obviously, opt for the standard library functions in a real production code.
    For this problem I wrote these macros to at least try and squeeze out a little performance
    boost.
*/

#define IS_ALNUM(c) (((c) >= 'A' && (c) <= 'Z') || ((c) >= 'a' && (c) <= 'z') || ((c) >= '0' && (c) <= '9'))
#define TO_LOWER(c) (((c) >= 'A' && (c) <= 'Z') ? (c) + 'a' - 'A' : (c))

bool isPalindrome(char* s) {
    size_t len = strlen(s);
    char* p = &s[len - 1];
    char a = '\0', b = '\0';
    while (s <= p) {
        a = *s;
        b = *p;
        if (!IS_ALNUM(a)) ++s;
        else if (!IS_ALNUM(b)) --p;
        else if (TO_LOWER(a) != TO_LOWER(b)) return 0;
        else ++s, --p;
    }
    return 1;
}
