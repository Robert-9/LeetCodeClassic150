/*
    给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

    你应当 保留 两个分区中每个节点的初始相对位置。

    双指针
*/
#include "../list_head.h"
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr){
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *larger = new ListNode(0);
        ListNode *temp = larger;
        ListNode *prev = dummy;
        ListNode *curr = prev->next;
        
        while(curr != nullptr){
            if(curr->val >= x){
                prev->next = curr->next;
                temp->next = curr;
                
                temp = temp->next;
                temp->next = nullptr;  // 这一步非常关键！！使用的是原链表的节点，则需切断与原链表的联系，否则会报错
                curr = prev->next;
            } else{
                prev = prev->next;
                curr = prev->next;
            }
        }
        prev->next = larger->next;
        return dummy->next;
    }
};

int main(){
    Solution solution;

    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(2);
    l1->next->next->next->next = new ListNode(5);
    l1->next->next->next->next->next = new ListNode(2);

    solution.partition(l1, 3);
}