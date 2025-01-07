/*
    给你一个二叉树的根节点 root ， 检查它是否轴对称。
*/

#include "../head_bt.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        return isSymmetricHelper(root->left, root->right);
    }

    bool isSymmetricHelper(TreeNode* leftSub, TreeNode* rightSub){ // 判断两个子树是否对称
        if(leftSub == nullptr && rightSub == nullptr){
            return true;
        } else if(leftSub == nullptr || rightSub == nullptr){
            return false;
        } else if(leftSub->val == rightSub->val){
            return isSymmetricHelper(leftSub->left, rightSub->right)
                && isSymmetricHelper(leftSub->right, rightSub->left);
        } else{
            return false;
        }


    }
};