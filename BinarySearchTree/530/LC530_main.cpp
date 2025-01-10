/*
    给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

    差值是一个正数，其数值等于两值之差的绝对值。


    测试已通过
    去掉全局变量的做法是在传参时传入参数的地址，这样参数值会跟着函数的计算一起被修改
*/
#include "../../BinaryTree/head_bt.h"

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int prev = -1;
        getMinimumDifferenceHelper(root, prev, minDiff);  // 注意这里的minDiff !! 其值会被修改
        return minDiff;
    }

    void getMinimumDifferenceHelper(TreeNode* root, int& prev, int& minDiff){
        if(root == nullptr) return ;

        getMinimumDifferenceHelper(root->left, prev, minDiff);

        if(prev != -1) {
            int diff = root->val - prev; // 计算当前差值
            minDiff = min(minDiff, diff); // 更新最小差值
        }
        prev = root->val;
        
        getMinimumDifferenceHelper(root->right, prev, minDiff);
    }
};