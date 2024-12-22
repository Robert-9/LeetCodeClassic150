/*
    将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

    测试已通过！时间空间效率都很高
*/
# include "../list_head.h"
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = new ListNode(0);
        ListNode* curRes = result;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        while(cur1 != nullptr && cur2 != nullptr){
            if(cur1->val <= cur2->val){
                curRes->next = cur1;
                cur1 = cur1->next;
            } else{
                curRes->next = cur2;
                cur2 = cur2->next;                
            }
            
            curRes = curRes->next;
        }

        while (cur1 != nullptr){
            curRes->next = cur1;
            cur1 = cur1->next;
            curRes = curRes->next;
        }
        while (cur2 != nullptr){
            curRes->next = cur2;
            cur2 = cur2->next; 
            curRes = curRes->next;
        }        

        return result->next;
    }
};

int main(){
    Solution solution;

    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode* res = solution.mergeTwoLists(l1, l2);

    while (res!=nullptr)
    {
        cout << (res->val) << "-";
        res = res->next;
    }
}