/*
    给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

    测试已通过  双指针
*/
#include "../list_head.h"
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr|| k == 0) {
            return head;
        }
        ListNode* temp = head;
        int len = 1;
        for (; temp->next != nullptr; len++) {
            temp = temp->next;
        }
        int fore = k % len;
        if(fore == 0){
            return head;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < fore; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* result = slow->next;
        slow->next = nullptr;
        fast->next = head;
        return result;
    }
};