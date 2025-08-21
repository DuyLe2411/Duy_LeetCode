/* Description Problem
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int lengthOfLastWord(char* s) {
    int length = 0;
    int i;
    for(i = 0; i < strlen(s); i++) {
        if (isalpha(s[i])) {
            length++;
        } else if (isspace(s[i])) {
            while(isspace(s[i])) {
                if (isalpha(s[i+1])) {
                    length = 0;
                    break;
                }
                i++;
            }
            if (i == strlen(s) - 1) return length;  
        }
    }
    return length;
}