/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/

#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    // Nếu kích thước mảng nhỏ hơn hoặc bằng 1, không thể mua và bán để có lợi nhuận.
    if (pricesSize <= 1) {
        return 0;
    }

    // Khởi tạo giá mua thấp nhất là giá ngày đầu tiên.
    int giaMuaThapNhat = prices[0];
    // Khởi tạo lợi nhuận tối đa là 0, vì nếu không có lợi nhuận thì sẽ trả về 0.
    int loiNhuanToiDa = 0;

    // Duyệt qua mảng bắt đầu từ ngày thứ hai.
    for (int i = 1; i < pricesSize; i++) {
        // Tính toán lợi nhuận tiềm năng nếu bán vào ngày hiện tại.
        int loiNhuanHienTai = prices[i] - giaMuaThapNhat;

        // Cập nhật lợi nhuận tối đa nếu tìm thấy lợi nhuận cao hơn.
        if (loiNhuanHienTai > loiNhuanToiDa) {
            loiNhuanToiDa = loiNhuanHienTai;
        }

        // Cập nhật giá mua thấp nhất nếu tìm thấy một giá thấp hơn vào ngày hiện tại.
        // Điều này đảm bảo 'giaMuaThapNhat' luôn là giá thấp nhất trước hoặc bằng ngày 'i'.
        if (prices[i] < giaMuaThapNhat) {
            giaMuaThapNhat = prices[i];
        }
    }

    return loiNhuanToiDa;
}