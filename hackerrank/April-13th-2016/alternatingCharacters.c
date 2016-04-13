/*
[ref.href] www.hackerrank.com/challenges/alternating-characters
"
  Shashank likes strings in which consecutive characters are different.
  For example, he likes ABABA, while he doesn't like ABAA. Given a 
  string containing characters AA and BB only, he wants to change it 
  into a string he likes. To do this, he is allowed to delete the 
  characters in the string.
  
  Your task is to find the minimum number of required deletions.
"
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main() {

    int testcount = 0;
    char c = '\0';
    while ((c = getchar()) && isdigit(c)) {
        testcount = testcount * 10 + c - '0';
    }
    
    char curr = '\0', prev = '\0';
    
    for (int i = 0; i < testcount; ++i) {
        curr = '\0', prev = '\0';
        int count = 0;
        while ((curr = getchar()) != '\n' && curr != EOF) {
            if (curr == prev) ++count;
            prev = curr;
        }
        printf("%d\n", count);
    }
    
    return 0;
}
