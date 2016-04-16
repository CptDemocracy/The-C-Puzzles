/*
[ref.href] leetcode.com/problems/find-minimum-in-rotated-sorted-array
"
  Suppose a sorted array is rotated at some pivot unknown to you beforehand.

  (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
  
  Find the minimum element.
"
*/

int findMin(int* nums, int numsSize) {
    if (!nums) return 0;
    int lo = 0;
    int hi = numsSize - 1;
    while (lo < hi) {
        int mp = (lo + hi) / 2;
        if (nums[hi] < nums[mp]) {
            lo = mp + 1;
        } else {
            hi = mp;
        }
    }
    return nums[lo];
}
