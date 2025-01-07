/*
    给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
    如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。


    分别判断左右子树和根节点是否相同 都相同则相同
*/

#include "../head_bt.h"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p != nullptr && q != nullptr){
            if(p->val != q->val){
                return false;
            }
            if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right)){
                return true;
            }
        } else if(p == nullptr && q == nullptr){
            return true;
        } else{
            return false;
        }
    }
};