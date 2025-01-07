/*
    给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

    前序 根左右
    中序 左根右
*/

#include "../head_bt.h"
class Solution1 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return nullptr;
        }
        
        return addNode(preorder, inorder);
    }
    TreeNode*  addNode(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]);

        int leftSubLen=0;// 通过中序算出左子树的长度（根节点以前的都是左子树）
        while(inorder[leftSubLen] != root->val){ // 从0下标开始，到根节点的前一个为止
            leftSubLen++;
        }

        vector<int> leftSubPreorder = {preorder.begin()+1, preorder.begin()+1+leftSubLen};
        vector<int> leftSubInrder = {inorder.begin(), inorder.begin()+leftSubLen};
        root->left = addNode(leftSubPreorder, leftSubInrder);

        vector<int> rightSubPreorder = {preorder.begin()+1+leftSubLen, preorder.end()};
        vector<int> rightSubInorder = {inorder.begin()+1+leftSubLen, inorder.end()};
        root->right = addNode(rightSubPreorder, rightSubInorder);
        return root;
    }
};

class Solution2 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }

        return addNode(preorder, 0, preorder.size(), inorder, 0,
                       inorder.size() - 1);
    }
    TreeNode* addNode(vector<int>& preorder, int preStart, int preEnd,
                      vector<int>& inorder, int inStart, int inEnd) {
        if (preStart >= preEnd || inStart > inEnd) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int leftSubLen = 0;

        // 通过中序算出左子树的长度（根节点以前的都是左子树）
        while (inorder[leftSubLen + inStart] !=
               root->val) { // 从0下标开始，到根节点的前一个为止
            leftSubLen++;
        }

        root->left = addNode(preorder, preStart + 1, preStart + leftSubLen + 1,  // 前序的第0个是根节点，第 1~leftSubLen+1 是左子树
                             inorder, inStart, inStart + leftSubLen - 1);  // 中序的第 0~leftSubLen-1 是左子树

        root->right = addNode(preorder, preStart + 1 + leftSubLen, preEnd,
                              inorder, inStart + 1 + leftSubLen, inEnd);
        return root;
    }
};