/*
    给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。

 
*/
#include "../../BinaryTree/head_bt.h"


int kthSmallest(TreeNode* root, int k) {
    int counter = 0;
    return kthSmallestHelper(root, k, counter);
}

int kthSmallestHelper(TreeNode* root, int k, int& counter) {
    if(root == nullptr) 
        return -1;
    int result = kthSmallestHelper(root->left, k, counter);
    if(result != -1) 
        return result;
    counter++;
    if(counter == k) 
        return root->val;
    return 
        kthSmallestHelper(root->right, k, counter);
}
