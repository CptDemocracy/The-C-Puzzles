/*
[ref.href] leetcode.com/problems/search-insert-position
"
  Given a sorted array and a target value, return the index if the target is found. 
  If not, return the index where it would be if it were inserted in order.
  You may assume no duplicates in the array.
  
  Here are few examples:
  
  [1,3,5,6], 5 → 2
  [1,3,5,6], 2 → 1
  [1,3,5,6], 7 → 4
  [1,3,5,6], 0 → 0
"
*/

#include <stdlib.h>

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

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    
    // find the matrix where target could potentially reside
    int lo = 0;
    int hi = matrixRowSize - 1;
    int mp = (lo + hi) / 2;
    
    while (lo <= hi) {
        if (matrix[mp][0] > target) {
            hi = mp - 1;
        } else if (matrix[mp][0] < target) {
            lo = mp + 1;
        } else {
            return true;
        }
        mp = (lo + hi) / 2;
    }
    
    // look for the item in the row where the target should potentially reside
    const int* arr = matrix[mp];
    lo = 0;
    hi = matrixColSize - 1;
    mp = (lo + hi) / 2;
    
    while (lo <= hi) {
        if (arr[mp] > target) {
            hi = mp - 1;
        } else if (arr[mp] < target) {
            lo = mp + 1;
        } else {
            return true;
        }
        mp = (lo + hi) / 2;
    }
    return false;
}
