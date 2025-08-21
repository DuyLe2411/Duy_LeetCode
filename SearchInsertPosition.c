/* Description Problem
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
*/

#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    if (numsSize == 0) return 0;
    int i;
    for(i = 0; i < numsSize; i++) {
        if (target == nums[i] || target < nums[i]) {
            return i;
            break;
        }
        if (i == (numsSize - 1)) {
            return i + 1;
            break;
        }
    }
    return 0;
}