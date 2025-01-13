/*
    给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。 


    找根节点
*/

#include "../../BinaryTree/head_bt.h"

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = merge(nums, 0, nums.size()-1);
        return root;
    }
    TreeNode* merge(vector<int>& nums, int left, int right){
        if(left > right) return nullptr;
        int mid = (left+right)/2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = merge(nums, left, mid-1);
        root->right = merge(nums, mid+1, right);

        return root;
    }
};