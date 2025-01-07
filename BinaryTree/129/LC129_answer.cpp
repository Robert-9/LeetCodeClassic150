#include "../head_bt.h"


class Solution {
public:
    int dfs(TreeNode* root, int currNum) {  // 到达root的父节点的路径数字和
        if (root == nullptr) {  
            return 0;  // 递归终止条件1  因为没限制root仅有一个节点为空的情况，也没有对输入判断为空直接返回，故需要这一步
        }
        int sum = currNum * 10 + root->val;  // 将前面路径的数字与当前节点的值拼接起来
        if (root->left == nullptr && root->right == nullptr) {
            return sum;  // 递归终止条件2  叶子节点返回
        } else {
            return dfs(root->left, sum) + dfs(root->right, sum);  // 目的是累加当前节点到其所有叶子节点的路径数字和
        }
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
