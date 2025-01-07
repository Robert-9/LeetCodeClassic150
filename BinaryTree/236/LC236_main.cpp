/*
    给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

        所有 Node.val 互不相同 
        p != q
        p 和 q 均存在于给定的二叉树中

    测试已通过
*/
#include "../head_bt.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath;
        getPath(root, pPath, p->val);
        vector<TreeNode*> qPath;
        getPath(root, qPath, q->val);

        int i=0;
        pPath.push_back(nullptr);
        qPath.push_back(nullptr);
        while(pPath[i]!=nullptr && qPath[i]!=nullptr && pPath[i]->val == qPath[i]->val){
            i++;
        }
        return i>0 ? pPath[i-1] : pPath[0];
    }
    bool getPath(TreeNode* root,vector<TreeNode*>& path, int val){
        if(root == nullptr){
            return 0;
        }
        path.push_back(root);
        if(root->val == val) {
            return 1;
        }
        else {
            if(getPath(root->left, path, val) || getPath(root->right, path, val)){
                return 1;
            }
            path.pop_back();
            return 0;
        }
    }
};