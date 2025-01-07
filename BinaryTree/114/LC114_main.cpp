/*
    给你二叉树的根结点 root ，请你将它展开为一个单链表：

    展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
    展开后的单链表应该与二叉树 先序遍历 顺序相同。
*/
#include "../head_bt.h"

class Solution {
public:
    void flatten(TreeNode* root) {
    
            flattenHelper(root);
    }
    void flattenHelper(TreeNode* root){
        if(root != nullptr){
            TreeNode* rightSub;
            TreeNode* current = root;
            if(root->right != nullptr){
                rightSub = root->right;
            } else{
                rightSub = nullptr;
            }
            
            root->right = root->left;
            root->left = nullptr;
            while(current->right != nullptr){
                current = current->right;
            }
            current->right = rightSub;
            flattenHelper(root->right);
        }
    }
};