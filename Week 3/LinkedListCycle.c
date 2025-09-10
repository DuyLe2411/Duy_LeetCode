/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

*/

#include <stdbool.h> 
#include <stddef.h>  

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    // Nếu danh sách rỗng hoặc chỉ có một nút, chắc chắn không có chu kỳ.
    if (head == NULL || head->next == NULL) {
        return false;
    }

    // Khởi tạo hai con trỏ: 'chayCham' (slow pointer) di chuyển 1 bước một lần,
    // và 'chayNhanh' (fast pointer) di chuyển 2 bước một lần.
    struct ListNode *chayCham = head;
    struct ListNode *chayNhanh = head;

    // Duyệt danh sách. Nếu có chu kỳ, 'chayNhanh' sẽ đuổi kịp 'chayCham'.
    // Điều kiện dừng: 'chayNhanh' hoặc 'chayNhanh->next' là NULL, nghĩa là không có chu kỳ và đã đến cuối danh sách.
    while (chayNhanh != NULL && chayNhanh->next != NULL) {
        chayCham = chayCham->next;        // Di chuyển 'chayCham' một bước
        chayNhanh = chayNhanh->next->next; // Di chuyển 'chayNhanh' hai bước

        // Nếu 'chayCham' và 'chayNhanh' gặp nhau, tức là có một chu kỳ.
        if (chayCham == chayNhanh) {
            return true;
        }
    }

    // Nếu vòng lặp kết thúc mà không gặp nhau, không có chu kỳ.
    return false;
}