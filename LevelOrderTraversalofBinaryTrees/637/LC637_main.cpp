/*
    给定一个非空二叉树的根节点 root , 以数组的形式返回每一层节点的平均值。与实际答案相差 10-5 以内的答案可以被接受
*/
#include "../../BinaryTree/head_bt.h"

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if(root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int layerSize = q.size();
            double sum = 0;
            for(int i=0; i<layerSize; i++){
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            result.push_back((double)sum/layerSize);
        } 
        return result;
    }   
};