/*
[ref.href] leetcode.com/problems/search-for-a-range
"
  Given a sorted array of integers, find the starting and ending position of a given target value.

  Your algorithm's runtime complexity must be in the order of O(log n).
  
  If the target is not found in the array, return [-1, -1].
  
  For example,
  Given [5, 7, 7, 8, 8, 10] and target value 8,
  return [3, 4].
"
*/

#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 int cmpInts(const int* ptra, const int* ptrb) {
     if (!ptra && !ptrb) return 0;
     else if (!ptra) return -1;
     else if (!ptrb) return 1;
     int x = *ptra;
     int y = *ptrb;
     if (x > y) return 1;
     else if (x < y) return -1;
     return 0;
 }
 
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 0;
    int* pair = (int*)calloc(2, sizeof(int));
    if (!pair) return NULL;
    int* ptarget = NULL;
    ptarget = bsearch(&target, nums, numsSize, sizeof(int), cmpInts);
    if (ptarget) 
    {
        int start = ptarget - nums;
        for ( ;
            start > 0
            && nums[start] == nums[start - 1];
            --start)
        {
            continue;
        }
        
        int end = start;
        for ( ;
            end < numsSize - 1
            && nums[end] == nums[end + 1]; 
            ++end) 
        {
            continue;
        }
        pair[0] = start;
        pair[1] = end;
    } else {
        memset(pair, -1, sizeof(int) * 2);
    }
    *returnSize = 2;
    return pair;
}
