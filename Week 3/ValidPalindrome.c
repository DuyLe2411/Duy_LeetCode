/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/

#include <stdbool.h> 
#include <string.h>  
#include <ctype.h>   // isalnum và tolower
#include <stdlib.h>  //  malloc 

bool isPalindrome(char* s) {
    // Xử lý trường hợp chuỗi đầu vào là NULL
    if (s == NULL) {
        return false;
    }

    int len = strlen(s);

    char* cleaned_s = (char *)malloc((len + 1) * sizeof(char));

    int k = 0; 
    for (int i = 0; i < len; i++) {
        // Kiểm tra xem ký tự có phải là chữ cái hoặc số không
        if (isalnum(s[i])) {
            // Chuyển đổi ký tự thành chữ thường 
            cleaned_s[k++] = tolower(s[i]);
        }
    }
    // Kết thúc chuỗi bằng ký tự null
    cleaned_s[k] = '\0';

    // Lấy độ dài của chuỗi 
    int cleaned_len = k;

    // kiểm tra tính đối xứng
    int left = 0;
    int right = cleaned_len - 1;

    while (left < right) {
        // Nếu các ký tự đối xứng không khớp, thì không phải palindrome
        if (cleaned_s[left] != cleaned_s[right]) {
            free(cleaned_s); 
            return false;
        }
        left++;  // Di chuyển con trỏ trái vào trong
        right--; // Di chuyển con trỏ phải vào trong
    }

    free(cleaned_s); 
    return true; // Nếu vòng lặp kết thúc mà không có sự không khớp, thì là palindrome
}
