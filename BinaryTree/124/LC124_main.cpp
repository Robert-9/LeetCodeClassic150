/*
    二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。
    该路径 至少包含一个 节点，且不一定经过根节点。
    路径和 是路径中各节点值的总和。
    给你一个二叉树的根节点 root ，返回其 最大路径和 。

    测试已通过，但复杂度较高
*/
#include "../head_bt.h"

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        TreeNode* currNode = root;
        queue<TreeNode*> q;
        int result = -INT_MAX;
        q.push(currNode);
        while (!q.empty()){
            currNode = q.front();
            int currMax = currNode->val+maxPathSumHelper(currNode->left) + maxPathSumHelper(currNode->right);
            if(currMax > result){
                result = currMax;
            }
            q.pop();
            if(currNode->left != nullptr){
                q.push(currNode->left);
            }
            if(currNode->right != nullptr){
                q.push(currNode->right);
            }
        }
        return result;

        
    }

    int maxPathSumHelper(TreeNode* root){
        if(root == nullptr) return 0;

        return root->val + max(maxPathSumHelper(root->left), maxPathSumHelper(root->right));
    }
};