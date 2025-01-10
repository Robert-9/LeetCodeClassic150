/*
    给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

    有效二叉搜索树定义如下：
        节点的左子树
        只包含 小于 当前节点的数。
        节点的右子树只包含 大于 当前节点的数。
        所有左子树和右子树自身必须也是二叉搜索树。


        如果是二叉搜索树，中序遍历的结果应该是升序排列
*/
#include "../../BinaryTree/head_bt.h"
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return false;

        long prev = LONG_MIN;
        return isValidBSTHelper(root, prev);
    }

    bool isValidBSTHelper(TreeNode* root, long& prev){
        if(root == nullptr) return true;

        if(!isValidBSTHelper(root->left, prev)) return false;

        if(root->val > prev){
            prev = root->val;
        } else {
            return false;
        }
            
         return isValidBSTHelper(root->right, prev);
    }
};