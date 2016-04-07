/*
[ref.href] leetcode.com/problems/counting-bits
"
    Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
    
    Example:
    For num = 5 you should return [0,1,1,2,1,2].
    
    Credits:
    Special thanks to @ syedee for adding this problem and creating all test cases.
"
*/

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    *returnSize = num + 1;
    int* bitCounts = (int*)calloc(num + 1, sizeof(int));
    if (!bitCounts) {
        return NULL;
    }
    
    int currnum = 0;
    while (currnum <= num) {
        int bits = currnum;
        int bitCount = 0;
        while (bits > 0) {
            if (bits & 1) {
                ++bitCount;
            }
            bits = ((unsigned)bits) >> 1;    
        }
        bitCounts[currnum] = bitCount;
        ++currnum;
    }
    // WARNING: returning a dynamically-alloc'ed
    // array, be advised, callers must free it themselves
    return bitCounts;
}
