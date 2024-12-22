/*
    给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
    k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
    你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

*/

#include "../list_head.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head ==nullptr || k == 1){
            return head;
        }
        ListNode *prev, *curr, *next;
        ListNode *temp;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        temp = dummy;
        prev = dummy;
        curr = dummy->next;
        next = curr->next;
        int len = 0;
        while(temp != nullptr){
            temp = temp->next;
            len++;
        }
        int times = len/k;
        for(int j=0; j<times; j++) {
            for(int i=1; i<k; i++) {
                if(next != nullptr){
                    curr->next = next->next;
                    next->next = prev->next;
                    prev->next = next;
                    next = curr->next;
                }
                else{
                    prev->next = next;
                    next = curr->next;
                }
            }   
        }
    }
};