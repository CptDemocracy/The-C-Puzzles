/*
[ref.href] leetcode.com/problems/rotate-array
"
  Rotate an array of n elements to the right by k steps.
  
  For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
"
*/

void rotate(int* nums, int numsSize, int k) {
    if (!nums) return;
    
    k = k % numsSize;
    if (k == 0) return;
    
    int* buffer = (int*)calloc(numsSize, sizeof(int));
    if (!buffer) return;
    
    int halfcount1 = numsSize - k;
    int halfcount2 = k;
    
    memcpy(buffer, &nums[halfcount1], halfcount2 * sizeof(int));
    memcpy(&buffer[halfcount2], nums, halfcount1 * sizeof(int));
    memcpy(nums, buffer, numsSize * sizeof(int));
    
    free(buffer);
}
