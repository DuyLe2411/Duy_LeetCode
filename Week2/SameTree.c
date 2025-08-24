/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.


Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false
*/

#include <stdbool.h> 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // TH1: Nếu cả hai thằng đều NULL thì là giống nhau
    if (p == NULL && q == NULL) {
        return true;
    }
    
    // TH2: Nếu chỉ một trong hai là NULL, chúng không giống nhau
    if (p == NULL || q == NULL) {
        return false;
    }
    
    // TH đệ quy: Kiểm tra giá trị của nút hiện tại
    // và gọi đệ quy cho cây con bên trái và bên phải
    return (p->val == q->val) && 
           isSameTree(p->left, q->left) && 
           isSameTree(p->right, q->right);
}