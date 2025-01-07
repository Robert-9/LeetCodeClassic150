/*
    给定一个二叉树 root ，返回其最大深度。
    二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数


    当前节点深度 = (左子树深度，右子树深度) + 1
*/

#include "../head_bt.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int leftDepth = 0;
        int rightDepth = 0;
        if (root == nullptr) {
            return 0;
        }
        if (root->left) {
            leftDepth = maxDepth(root->left);
        }
        if (root->right) {
            rightDepth = maxDepth(root->right);
        }
        return max(leftDepth, rightDepth) + 1;
    }
};

int main(){
    Solution solution;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << solution.maxDepth(root) << endl;

}