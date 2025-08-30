/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]

*/

#include <stdlib.h> 
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    // Nếu numRows là 0, không có gì để tạo
    if (numRows == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Cấp phát bộ nhớ cho mảng chứa các con trỏ tới từng hàng (row)
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    // Cấp phát bộ nhớ cho mảng lưu kích thước của từng hàng
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    
    // Đặt số lượng hàng trả về
    *returnSize = numRows;

    // Duyệt qua từng hàng để cấp phát bộ nhớ và điền giá trị
    for (int i = 0; i < numRows; i++) {
        // Mỗi hàng thứ i sẽ có i+1 phần tử
        int current_row_size = i + 1;
        (*returnColumnSizes)[i] = current_row_size; // Lưu kích thước hàng
        
        // Cấp phát bộ nhớ cho các phần tử của hàng hiện tại
        triangle[i] = (int*)malloc(current_row_size * sizeof(int));

        // Điền giá trị vào hàng hiện tại
        for (int j = 0; j < current_row_size; j++) {
            // Phần tử đầu tiên (j=0) và cuối cùng (j=current_row_size-1) của mỗi hàng luôn là 1
            if (j == 0 || j == current_row_size - 1) {
                triangle[i][j] = 1;
            } else {
                // Các phần tử khác là tổng của hai phần tử phía trên nó ở hàng trước
                // Điều này áp dụng cho các hàng từ thứ 2 trở đi (i >= 2)
                // và các phần tử không phải đầu hoặc cuối
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
    }

    return triangle;
}