/*
[ref.href] leetcode.com/problems/search-a-2d-matrix
"
  Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

  Integers in each row are sorted from left to right.
  The first integer of each row is greater than the last integer of the previous row.
  For example,
  
  Consider the following matrix:
  
  [
    [1,   3,  5,  7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
  ]
  Given target = 3, return true.
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
    const int* ptarget = NULL;
    for (int i = 0; i < matrixRowSize; ++i) {
        ptarget = bsearch(&target, matrix[i], matrixColSize, sizeof(int), cmpInts);
        if (ptarget) return 1;
    }
    return 0;
}
