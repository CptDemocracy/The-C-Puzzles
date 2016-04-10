/*
[ref.href] leetcode.com/problems/plus-one
"
  Given a non-negative number represented as an array of digits, plus one to the number.
  The digits are stored such that the most significant digit is at the head of the list.
"
*/

#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* result = (int*)calloc(digitsSize, sizeof(int));
    if (!result) return NULL;

    int sum = digits[digitsSize - 1] + 1;
    result[digitsSize - 1] = sum % 10;
    int carry = sum / 10;

    for (int i = digitsSize - 2; i >= 0; --i) {
        sum = digits[i] + carry;
        carry = sum / 10;
        result[i] = sum % 10;
    }
    if (carry > 0) {
        int* newResult = (int*)calloc(digitsSize + 1, sizeof(int));
        if (!newResult) {
            free(result);
            return NULL;
        }
        memcpy(&newResult[1], result, digitsSize * sizeof(int));
        free(result);
        result = newResult;
        result[0] = carry;
        *returnSize = digitsSize + 1;
    }
    else {
        *returnSize = digitsSize;
    }

    return result;
}
