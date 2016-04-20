/*
[ref.href] leetcode.com/problems/longest-common-prefix
"
  Write a function to find the longest common prefix string amongst an array of strings.
"
*/

#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (!strs || strsSize < 1) {
        return (char*)calloc(1, sizeof(char));
    }
    
    int i = 1;
    int j = 0;
    if (strsSize == 1) { 
        j = strlen(strs[0]); 
    } else {
        while (strs[i][j] != '\0') {
            if (strs[0][j] != strs[i][j]) break;
            ++i;
            
            if (i == strsSize) i = 1, ++j;
        }
    }
    
    char* prefix = (char*)calloc(j + 1, sizeof(char));
    if (!prefix) return NULL;
    strncpy(prefix, strs[0], j);
    return prefix;
}
