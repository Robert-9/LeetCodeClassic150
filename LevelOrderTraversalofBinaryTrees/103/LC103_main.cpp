/*
    给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

    测试已通过
*/
#include "../../BinaryTree/head_bt.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;

        
        queue<TreeNode*> qNodes;
        qNodes.push(root);
        int depth = 1;

        while(!qNodes.empty()){
            int LayerSize = qNodes.size();
            deque<int> dqLayerVal;
            for(int i=0; i<LayerSize; i++){
                TreeNode* curr = qNodes.front();
                qNodes.pop();
                if(curr->left) qNodes.push(curr->left);
                if(curr->right) qNodes.push(curr->right);

                if(depth%2){
                    dqLayerVal.push_back(curr->val);
                } else {
                    dqLayerVal.push_front(curr->val);
                }
            }
            result.push_back({dqLayerVal.begin(), dqLayerVal.end()});
            
        }
    }
};