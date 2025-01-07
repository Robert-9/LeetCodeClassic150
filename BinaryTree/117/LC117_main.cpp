/*
    填充Node的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。
    初始状态下，所有 next 指针都被设置为 NULL 。

    
 */
#include "../head_bt.h"

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int num = q.size();
            for(int i=0; i<num; i++){
                Node* current = q.front();
                q.pop();
                if(i != num-1){
                    current->next = q.front();
                } else {
                    current->next = nullptr;
                }
                
                if(current->left != nullptr){
                    q.push(current->left);
                }
                if(current->right != nullptr){
                    q.push(current->right);
                }
            }
            
        }
    }
};