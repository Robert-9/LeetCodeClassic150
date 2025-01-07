#include "../head_bt.h"


class Solution {  
	public:  
        void flatten(TreeNode* root) {  
            while (root != nullptr) {  
                if (root->left == nullptr) {// 当前节点没有左子树，直接移动到右子树  
                    root = root->right;  
                } else {  
                    // 找左子树的最右边的节点  
                    TreeNode* pre = root->left;  
                    while (pre->right != nullptr) {  
                        pre = pre->right;  
                    }  
                    
                    pre->right = root->right;   // 将原右子树接到左子树的最右边节点  
                    
                    root->right = root->left;  // 将左子树放到右子树的位置  
                    root->left = nullptr;  
                    
                    root = root->right;  // 继续处理下一个节点（当前节点的右子树）  
                }  
            }  
        }  
	}; 
