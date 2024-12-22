#include "list_head.h"

class Solution {  
public:  
    ListNode* deleteDuplicates(ListNode* head) {  
        if (!head || !head->next) return head;  
  
        ListNode* dummy = new ListNode(0); // 使用0作为虚拟头节点的值  
        dummy->next = head;  
        ListNode* prev = dummy;  
        ListNode* current = head;  
  
        while (current && current->next) {  
            if (current->val == current->next->val) {  
                int duplicateVal = current->val;  
                // 跳过所有值等于 duplicateVal 的节点  
                while (current && current->val == duplicateVal) {  
                    current = current->next;  
                }  
                prev->next = current; // 连接到第一个不同的节点  
            } else {  
                prev = current;  
                current = current->next;  
            }  
        }  
  
        ListNode* newHead = dummy->next;  
        delete dummy; // 释放虚拟头节点  
        return newHead;  
    }  
};  