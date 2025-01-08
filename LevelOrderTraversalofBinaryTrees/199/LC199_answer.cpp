/*
    Solution1广度优先（层序）
    Solution2深度优先（递归）
*/

#include "../../BinaryTree/head_bt.h"


class Solution1 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int layerSize = q.size();
            for (int i = 0; i < layerSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                
                // 如果是每层最后一个节点，加入结果
                if (i == layerSize - 1) {
                    result.push_back(curr->val);
                }
                
                // 添加左右子节点到队列
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
        return result;
    }
};


class Solution2 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }

    void dfs(TreeNode* node, int depth, vector<int>& result) {
        if (!node) return;

        // 如果当前深度尚未记录节点，则记录该节点
        if (depth == result.size()) {  // 非常巧妙
            result.push_back(node->val);
        }

        // 优先递归右子树
        dfs(node->right, depth + 1, result);
        dfs(node->left, depth + 1, result);
    }
};
