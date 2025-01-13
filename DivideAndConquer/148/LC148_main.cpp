/*
    给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
*/

#include "../../List/list_head.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* curr = head;
        int nodeNum = 0;
        while(curr != nullptr){
            curr = curr->next;
            nodeNum++;
        }
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* result = merge(dummyHead->next, 0, nodeNum);
    }
    ListNode* merge(ListNode* head, int left, int right){
        if(left >= right){
            return head;
        }
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* curr = dummyHead->next;

        int mid = (left+right)/2;
        for(int i=0; i<mid; i++){
            curr = curr->next;
        }
        ListNode* leftSubHead = merge(head, left, mid);
        ListNode* rightSubHead = merge(curr, mid+1,right);

        
        while(leftSubHead != nullptr && rightSubHead != nullptr){
            ListNode* next;
            if(leftSubHead->val < rightSubHead->val){
                next = new ListNode(leftSubHead->val);
                leftSubHead = leftSubHead->next;
            } else {
                next = new ListNode(rightSubHead->val);
                rightSubHead = rightSubHead->next;
            }
            curr->next = next;
            curr = curr->next;
        }

        while(leftSubHead != nullptr){
            ListNode* next;
            if(leftSubHead!=nullptr){
                next = new ListNode(leftSubHead->val);
                leftSubHead = leftSubHead->next;
            } 
            curr->next = next;
        }
        while(rightSubHead != nullptr){
            ListNode* next;
            if(rightSubHead!=nullptr){
                next = new ListNode(rightSubHead->val);
                rightSubHead = rightSubHead->next;
            } 
            curr->next = next;
        }
        return dummyHead->next;

    }
};