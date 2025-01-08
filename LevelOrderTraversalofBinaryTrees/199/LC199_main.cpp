/*
    给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

    测试已通过 answer中给出了gpt的更规整的代码，并给了dfs bfs两种解法
*/

#include "../../BinaryTree/head_bt.h"


class Solution1 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int layerNodeNum = q.size();
            TreeNode* curr;
            while(layerNodeNum>0){
                curr = q.front();
                q.pop();
                layerNodeNum--;
                if(curr->left != nullptr){
                    q.push(curr->left);
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
            }
            result.push_back(curr->val);
        }
        return result;
    }
};

