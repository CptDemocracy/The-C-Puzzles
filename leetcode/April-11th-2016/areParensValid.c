/*
[ref.href] leetcode.com/problems/valid-parentheses
"
  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
  
  The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
"
*/

#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define STACK_INIT_CAPACITY 32
#define STACK_CAPACITY_MUL  2

int isValid(const char* s) {
    const char OP_PARENS[CHAR_MAX] = {
        ['('] = ')',
        ['['] = ']',
        ['{'] = '}',
        0
    };
    
    const char CL_PARENS[CHAR_MAX] = {
        [')'] = '(',
        [']'] = '[',
        ['}'] = '{',
        0
    };
    
    int stackCapacity = STACK_INIT_CAPACITY;
    char* stack = (char*)malloc(sizeof(char) * stackCapacity);
    if (!stack) return 0;
    int stackCount = 0;
    
    char c = '\0';
    while ((c = *s) != '\0') {
        if (OP_PARENS[c]) {
            if (stackCount >= stackCapacity) {
                int newStackCapacity = stackCapacity * STACK_CAPACITY_MUL;
                char* newStack = (char*)realloc(stack, newStackCapacity);
                if (!newStack) {
                    free(stack);
                    return 0;
                }
                stack = newStack;
                stackCapacity = newStackCapacity;
            }
            stack[stackCount] = c;
            ++stackCount;
        }
        else if (CL_PARENS[c]) {
            if (stackCount < 1) {
                return 0;
            }
            else if (stack[stackCount - 1] == CL_PARENS[c]) {
                --stackCount;
            } 
            else return 0;
        }
        ++s;
    }
    free(stack);
    return stackCount == 0;
}
