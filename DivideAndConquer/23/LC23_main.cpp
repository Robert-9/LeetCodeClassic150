/*
    给你一个链表数组，每个链表都已经按升序排列。
    请你将所有链表合并到一个升序链表中，返回合并后的链表。


    测试已通过
    采用归并的方法
*/
#include "../head_d&c.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        ListNode* result = mergeKListsHelper(lists, 0, lists.size()-1);
        return result;
    }
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end){
        if(start >= end) return lists[end];

        int mid = (start + end) / 2;
        ListNode* left = mergeKListsHelper(lists, start, mid);
        ListNode* right = mergeKListsHelper(lists, mid+1, end);

        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* leftCurr = left;
        ListNode* rightCurr = right;
        ListNode* dummyHead = new ListNode (0);
        ListNode* curr = dummyHead;
        while(leftCurr != nullptr && rightCurr != nullptr){
            if(leftCurr->val <= rightCurr->val){
                curr->next = leftCurr;
                leftCurr = leftCurr->next;
            } else{
                curr->next = rightCurr;
                rightCurr = rightCurr->next;                
            }
            curr =  curr->next;
            
        }
        if(leftCurr != nullptr){
            curr->next = leftCurr;
        }
        if(rightCurr != nullptr){
            curr->next = rightCurr;
        }
        return dummyHead->next;
    }
};