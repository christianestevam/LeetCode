/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left 
subtree
 of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Input: root = [2,1,3]
Output: true

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {        
        return isValidBST(root, nullptr, nullptr);
    }
    
    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(root == nullptr) {
            return true;
        }
        if(min != nullptr && root->val <= min->val) {
            return false;
        }
        if(max != nullptr && root->val >= max->val) {
            return false;
        }
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);
    }
};

 