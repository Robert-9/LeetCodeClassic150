/*
    给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
*/
#include "../head_bt.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        return invertTreeHelper(root);
    }
    TreeNode* invertTreeHelper(TreeNode* root){
        if(root == nullptr){
            return root;
        }
        invertTreeHelper(root->left);
        invertTreeHelper(root->right);
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        return root;
    }
};