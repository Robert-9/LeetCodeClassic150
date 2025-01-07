/*
    给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
    每条从根节点到叶节点的路径都代表一个数字：
        例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
    计算从根节点到叶节点生成的 所有数字之和 。


    测试已通过
*/
#include "../head_bt.h"

class Solution {
public:
    vector<int> rootValVec;
    int result;
    int sumNumbers(TreeNode* root) {
        sumNumbersHelper(root);
        return result;
    }
    void sumNumbersHelper(TreeNode* root) {
        if(root == nullptr) return ;
        rootValVec.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr){  // 取出计算路径代表的数
            result += calPathSum(rootValVec);
        } 
        else if(root->right == nullptr){  // 区分左右为空的情况，以免在有一侧的子树为空时仍做弹出操作，将根节点从vec弹出了
            sumNumbersHelper(root->left);
            rootValVec.pop_back();
        }
        else if(root->left == nullptr){
            sumNumbersHelper(root->right);
            rootValVec.pop_back();
        }else {
            sumNumbersHelper(root->left);
            rootValVec.pop_back();
            sumNumbersHelper(root->right);
            rootValVec.pop_back();
        }
    }

    int calPathSum(vector<int> path){
        long weight = 1;  // 避免溢出
        int sum = 0;
        for(int i=path.size()-1; i>=0; i--){
            sum += path[i]*weight;
            weight *= 10;
        }
        return sum;
    }
};