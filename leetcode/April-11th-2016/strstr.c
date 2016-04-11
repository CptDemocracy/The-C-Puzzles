/*
[ref.href] leetcode.com/problems/implement-strstr
"
  Implement strStr().
  
  Returns the index of the first occurrence of needle in haystack, or -1 
  if needle is not part of haystack.
"
*/

#include <stdlib.h>
#include <string.h>

void kmpInitDFA(int* dfa, const char* pat, int psize) {
    int k = -1;
    dfa[0] = k;
    for (int i = 1; i < psize; ++i) {
        while (k > -1 && pat[i] != pat[k + 1]) {
            k = dfa[k];
        }
        if (pat[i] == pat[k + 1]) {
            ++k;
        }
        dfa[i] = k;
    }
}

int strStr(const char* haystack, const char* needle) {
    size_t hsize = strlen(haystack);
    size_t psize = strlen(needle);
    if (psize < 1) return 0;
    int index = -1;
    int* dfa = (int*)calloc(psize, sizeof(int));
    if (!dfa) return index;
    kmpInitDFA(dfa, needle, psize);
    int k = -1;
    for (int i = 0; i < hsize; ++i) {
        while (k > -1 && needle[k + 1] != haystack[i]) {
            k = dfa[k];
        }
        if (needle[k + 1] == haystack[i]) {
            ++k;
        }
        if (k == psize - 1) {
            index = i - k;
            break;
        }
    }
    free(dfa);
    return index;
}
