/*
[ref.href] leetcode.com/problems/merge-sorted-array
"
  Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

  Note:
  You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional 
  elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
"
*/

#include <string.h>
#include <stdlib.h>

void merge(int* nums1, int m, int* nums2, int n) {
    
    int total = m + n;
    int* buffer = (int*)calloc(total, sizeof(int));
    if (!buffer) return;
    
    int k = 0;
    int i = 0;
    int j = 0;
    while (k < total) {
        if (i >= m && j < n) {
            buffer[k] = nums2[j];
            ++j;
        }
        else if (i < m && j >= n) {
            buffer[k] = nums1[i];
            ++i;
        }
        else if (nums1[i] > nums2[j]) {
            buffer[k] = nums2[j];
            ++j;
        }
        else {
            buffer[k] = nums1[i];
            ++i;
        }
        ++k;
    }
    memcpy(nums1, buffer, sizeof(int) * total);
    free(buffer);
}
