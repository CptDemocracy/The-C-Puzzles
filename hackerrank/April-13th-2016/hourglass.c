/*
[ref.href] hackerrank.com/challenges/2d-array
"
  You are given a 2D array with dimensions 6*6. An hourglass in an array is 
  defined as a portion shaped like this:
  
  a b c
    d
  e f g
  
  For example, if we create an hourglass using the number 1 within an array 
  full of zeros, it may look like this:
  
  1 1 1 0 0 0
  0 1 0 0 0 0
  1 1 1 0 0 0
  0 0 0 0 0 0
  0 0 0 0 0 0
  0 0 0 0 0 0
  
  Actually, there are many hourglasses in the array above. The three topmost 
  hourglasses are the following:
  
  1 1 1     1 1 0     1 0 0
    1         0         0
  1 1 1     1 1 0     1 0 0
  
  The sum of an hourglass is the sum of all the numbers within it. The sum for 
  the hourglasses above are 7, 4, and 2, respectively.
  
  In this problem, you have to print the largest sum among all the hourglasses 
  in the array.
"
*/

#include <limits.h>
#include <stdio.h>

#define ROWS    6
#define COLS    6

#define HOURGLASS_HEIGHT    3
#define HOURGLASS_WIDTH     3

int main(){
	// BEGIN problem-supplied code 
    int arr[ROWS][COLS] = { 0 };
    for(int arr_i = 0; arr_i < ROWS; arr_i++){
       for(int arr_j = 0; arr_j < COLS; arr_j++){
          scanf("%d",&arr[arr_i][arr_j]);
       }
    }    
    // END problem-supplied code
    int maxsum = INT_MIN;
    int sum = 0;
    for (int i = 0; i <= ROWS - HOURGLASS_WIDTH; ++i) {        
        for (int j = 0; j <= COLS - HOURGLASS_HEIGHT; ++j) {
			sum = 0;
            int k = 0;
            for (k = 0; k < HOURGLASS_WIDTH; ++k) {
                sum += arr[i][j + k];
            }
            for (k = 0; k < HOURGLASS_WIDTH; ++k) {
                sum += arr[i + HOURGLASS_HEIGHT - 1][j + k];
            }
			for (k = 1; k < HOURGLASS_HEIGHT - 1; ++k) {
				sum += arr[k + i][j + HOURGLASS_WIDTH / 2];
			}
			if (sum > maxsum) maxsum = sum;
        }        
    }
    printf("%d\n", maxsum);
   
    return 0;
}
