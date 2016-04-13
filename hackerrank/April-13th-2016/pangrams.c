/*
[ref.href] hackerrank.com/challenges/pangrams
"
  Given a sentence ss, tell if it is a pangram or not.
"
*/

#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdio.h>

int main() {    
    
    // create a hash table
    int table[UCHAR_MAX] = { 0 };
    
    const int ALPHA_LENGTH = 'z' - 'a' + 1;
    
    // collect user input
    char c = '\0';
    int alphacount = ALPHA_LENGTH;
    size_t bucket = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        c = tolower(c);
        // check input against the hash table
        bucket = (unsigned char)c;
        if (isalpha(c) && !table[bucket]) {
            table[bucket] = 1;
            --alphacount;
        }
    }
    
    if (alphacount < 1) puts("pangram");
    else puts("not pangram");
    
    return 0;
}
