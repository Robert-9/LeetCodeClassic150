/*
    给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）
*/

#include "../../BinaryTree/head_bt.h"


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int layerSize = q.size();
            vector<int> layerNodes;
            for(int i=0; i<layerSize; i++){
                TreeNode* curr = q.front();
                q.pop();
                layerNodes.push_back(curr->val);
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            result.push_back(layerNodes);
        } 
        return result;      
    }
};