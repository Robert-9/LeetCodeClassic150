/*
    给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
*/
#include "list_head.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        ListNode *dummy = new ListNode(10000);
        dummy->next = head;
        ListNode *prev, *curr;

        prev = dummy;
        curr = prev->next;

        while (curr != nullptr)
        {
            while (prev->val == curr->val)
            {
                curr = curr->next;
            }
            prev->next = curr;
        }
        return dummy->next;
    }
};