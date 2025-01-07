/*
    给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

    前序 根左右
    中序 左根右
    后序 左右根
*/


#include "../head_bt.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return addNode(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode* addNode(vector<int>& inorder,int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd){
        if(inStart >= inEnd || postStart >= postEnd){
            return nullptr;
        }
        TreeNode *root = new TreeNode(postorder[postEnd]);  // 后序的最后一个是总的根

        int leftSubLen = 0;
        while(inorder[leftSubLen] != root->val){
            leftSubLen++;
        }

        root->left = addNode(inorder, inStart, inStart+leftSubLen-1, 
                                postorder, postStart, postStart+leftSubLen-1);
        root->right = addNode(inorder, inStart+leftSubLen+1, inEnd, 
                                postorder, postStart+leftSubLen+1, postEnd-1);
        return root;
    }
};