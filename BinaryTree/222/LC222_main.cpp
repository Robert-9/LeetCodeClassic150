/*
    给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
*/
#include "../head_bt.h"

class Solution {
private:
    int lastLayerNum = 0;
    int binarySearch(TreeNode* root, int left, int right, int depth){  // 返回最后一层的节点数
        if(root == nullptr) return 0;
        if(left >= right) return left;
        if(depth == 2){
            if(root->left == nullptr) return left;
            else if(root->right == nullptr) return left+1;
            else return left+2;
        }

        TreeNode* curr = root->left;
        int counter = 2;

        while(curr != nullptr && counter < depth){
            curr = curr->right;
            counter++;
        }
        if (curr == nullptr) 
            return binarySearch(root->left, left, right-(right-left)/2, depth-1);
        else 
            return binarySearch(root->right, left+(right-left)/2, right, depth-1);
    }
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        TreeNode* leftSub = root;
        int leftDepth = 1;
        TreeNode* rightSub = root;
        int rightDepth = 1;

        while(leftSub->left != nullptr){
            leftSub = leftSub->left;
            leftDepth++;
        }        
        while(rightSub->right != nullptr){
            rightSub = rightSub->right;
            rightDepth++;
        }
        if(leftDepth == rightDepth) {  // 满的 公式计算  仅一个节点也会是满的
            return pow(2, rightDepth)-1;
        }
        else {  // 不满 二分查找
            return pow(2, rightDepth)-1 + binarySearch(root, 0, pow(2, leftDepth-1), leftDepth);
        }
    }

};