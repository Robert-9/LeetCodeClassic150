/*
    每个节点的最大路径和，考虑了两部分：
        以当前节点为顶点，包括它的左右子树路径的和。
        仅选择一个子树的路径和，作为当前节点的最大贡献值返回给父节点。
*/

#include "../head_bt.h"

class Solution {  
private:  
    int maxSum = INT_MIN;  
  
public:  
    int maxGain(TreeNode* node) {  
        if (node == nullptr) {  
            return 0;  
        }  
          
        // 递归计算左右子节点的最大贡献值  
        // 只有在最大贡献值大于 0 时，才会选取对应子节点  
        int leftGain = max(maxGain(node->left), 0);  
        int rightGain = max(maxGain(node->right), 0);  
  
        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值  
        int priceNewpath = node->val + leftGain + rightGain;  
  
        // 更新答案  
        maxSum = max(maxSum, priceNewpath);  
  
        // 返回节点的最大贡献值  
        return node->val + max(leftGain, rightGain);  
    }  
  
    int maxPathSum(TreeNode* root) {  
        maxGain(root);  
        return maxSum;  
    }  
}; 