/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 
Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,null,3,null,3]
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

// Hàm trợ giúp để kiểm tra xem hai cây con có đối xứng với nhau không
bool laDoiXung(struct TreeNode* trai, struct TreeNode* phai) {
    if (trai == NULL && phai == NULL) {
        return true;
    }
    
    if (trai == NULL || phai == NULL) {
        return false;
    }
    

    return (trai->val == phai->val) &&
           laDoiXung(trai->left, phai->right) &&
           laDoiXung(trai->right, phai->left);
}

bool isSymmetric(struct TreeNode* root) {
    // Nếu cây rỗng, nó được coi là đối xứng
    if (root == NULL) {
        return true;
    }
    
    return laDoiXung(root->left, root->right);
}