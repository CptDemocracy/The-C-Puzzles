/*
[ref.href] leetcode.com/problems/find-peak-element
"
  A peak element is an element that is greater than its neighbors.

  Given an input array where num[i] ≠ num[i+1], find a peak element and 
  return its index.
  
  The array may contain multiple peaks, in that case return the index to 
  any one of the peaks is fine.
  
  You may imagine that num[-1] = num[n] = -∞.
  
  For example, in array [1, 2, 3, 1], 3 is a peak element and your function 
  should return the index number 2.
  
  click to show spoilers.
  
  Credits:
  Special thanks to @ts for adding this problem and creating all test cases.
"
*/

int findPeakElement(int* nums, int numsSize) {
    int max = nums[0];
    int i = 1;
    while (i < numsSize) {
        if (nums[i] > max) {
            max = nums[i];
        }
        else if (nums[i] < max) {
			break;
        }
        ++i;
    }
    return i - 1;
}
