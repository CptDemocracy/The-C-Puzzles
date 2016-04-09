/*
[ref.href] leetcode.com/problems/contains-duplicate
"
    Given an array of integers, find if the array contains any duplicates. 
    Your function should return true if any value appears at least twice 
    in the array, and it should return false if every element is distinct.
"
*/

int cmpInts(const int* ptr1, const int* ptr2) {
    if (!ptr1 && !ptr2) return 0;
    if (!ptr1) return -1;
    if (!ptr2) return 1;
    int a = *ptr1;
    int b = *ptr2;
    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmpInts);
    for (int i = 0; i < numsSize - 1; ++i) {
        if (nums[i] == nums[i + 1]) {
            return 1;
        }
    }
    return 0;
}
