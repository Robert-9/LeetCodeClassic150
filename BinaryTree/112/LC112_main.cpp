/*
    给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。
    判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
    如果存在，返回 true ；否则，返回 false

    
    测试已通过
*/
#include "../head_bt.h"

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            if(targetSum == 0) return true;
            else return false;
        }
        return hasPathSumHelper(root, &targetSum, 0);
    }

    bool hasPathSumHelper(TreeNode* root, int* tarSumAddr, int currSum){
        currSum += root->val;

        if(root->left == nullptr && root->right == nullptr){
            if(currSum == *tarSumAddr){
                return true;
            }
            else return false;
        }
        if(root->left != nullptr) 
            return hasPathSumHelper(root->left, tarSumAddr, currSum);
        
        currSum -= root->left->val;

        if(root->right != nullptr) 
            return hasPathSumHelper(root->right, tarSumAddr, currSum);
        currSum -= root->right->val;

    }
};