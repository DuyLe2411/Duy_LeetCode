/* Description Problem
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false


*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    char stack[strlen(s) + 1];
    int top = -1;

    if (s == NULL || *s == '\0') {
        return true;
    }

    for (int i = 0; s[i] != '\0'; i++) {
        char current_char = s[i];
        if (current_char == '(' || current_char == '[' || current_char == '{') {
            top++;
            stack[top] = current_char;
        } else if (current_char == ')' || current_char == ']' || current_char == '}') {
            if (top == -1) { // Dâu đóng ngoặc nằm ở đầu luôn khỏi check ==> khỏe
                return false;
            }
            char last_open = stack[top];
            if ((current_char == ')' && last_open == '(') ||
                (current_char == ']' && last_open == '[') ||
                (current_char == '}' && last_open == '{')) {
                top--; // Khớp lệnh thì vứt 1  ngoặc mở gần nhất r kiểm tra tiếp
            } else {
                return false; // Không đúng thì sai rồi`khỏi cần check tiếp
            }
        }
    }
    return top == -1;
}