/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:
Input: nums = [2,2,1]

Output: 1

Example 2:
Input: nums = [4,1,2,1,2]

Output: 4

Example 3:
Input: nums = [1]

Output: 1
*/

#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    // Nếu mảng chỉ có một phần tử, đó chính là số duy nhất.
    if (numsSize == 1) {
        return nums[0];
    }

    // Sử dụng toán tử XOR để tìm số duy nhất.
    // x ^ x = 0 
    // x ^ 0 = x 
    // x ^ y ^ x = y 
    int soDuyNhat = 0;
    for (int i = 0; i < numsSize; i++) {
        soDuyNhat ^= nums[i]; // XOR từng phần tử vào biến soDuyNhat
    }

    return soDuyNhat;
}