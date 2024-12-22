/*
    给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/
#include "list_head.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr){
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *fast, *slow, *prev;
        fast = dummy;
        prev = dummy;
        slow = prev->next;
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
            prev = prev->next;
        }
        prev->next = slow->next;
        return dummy->next;
    }
};