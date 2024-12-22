/*
    给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

    请你将两个数相加，并以相同形式返回一个表示和的链表。

    你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

// #include <iostream>
// #include <algorithm>
// using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

# include "../list_head.h"
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        
        ListNode* result = new ListNode(0);
        ListNode* sum = result;
        int carryBit = 0;

        while(temp1 != nullptr && temp2 != nullptr) {
            sum->next = new ListNode (temp1->val + temp2->val + carryBit);
            
            if(sum->next->val >= 10){
                carryBit = 1;
                sum->next->val -= 10;
            } else{
                carryBit = 0;
            }
            sum = sum->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1 != nullptr) {
            sum->next = new ListNode (temp1->val + carryBit);
            if(sum->next->val >= 10){
                carryBit = 1;
                sum->next->val -= 10;
            } else{
                carryBit = 0;
            }            
            sum = sum->next;
            temp1 = temp1->next;
        }
        
        while(temp2 != nullptr){
            sum->next = new ListNode (temp2->val + carryBit);
            if(sum->next->val >= 10){
                carryBit = 1;
                sum->next->val -= 10;
            } else{
                carryBit = 0;
            }
            sum = sum->next;
            temp2 = temp2->next;
        }
        if(carryBit == 1){
            sum->next = new ListNode (1);
        }

        return result->next;             
    }
};

int main(){
    Solution solution;
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode* res = solution.addTwoNumbers(l1, l2);

    while (res!=nullptr)
    {
        cout << (res->val) << "->";
        res = res->next;
    }
    
}