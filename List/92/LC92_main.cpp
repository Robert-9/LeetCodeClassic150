/*
    给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

    看了思路后，又debug + 手写思考 整了挺久才整出来

*/

#include "../list_head.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || head == nullptr) {
            return head;
        }
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode *leftNode;
        ListNode *prev, *curr, *next;
        ListNode* temp = dummyhead;

        // 保存左节点:左边的左边，为避免第一个就是要反转的，需要用dummyhead
        for (int i = 0; i < left - 1; i++) {
            temp = temp->next;
        }
        leftNode = temp;

        // 反转中间的，left != right 则至少有两个点，curr一定有next
        prev = leftNode;
        curr = prev->next;
        next = curr->next; 

        // prev保持为要反转的区间的前一个点，总是指向已经反转的部分的起点(即原顺序的最后一个点)；
        // curr保持为已经反转的部分的最后一个点(即原顺序的第一个点)，总是指向next
        for (int i = 0; i < right - left; i++) { // 循环一次，掉换两个点，两次三个点
            if (next != nullptr) {  
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            } else {
                prev->next = next;
                next = curr->next;
            }
        }
        return dummyhead->next;
    }
};

int main(){
    Solution solution;

    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    // l1->next->next = new ListNode(3);
    // l1->next->next->next = new ListNode(4);
    // l1->next->next->next->next = new ListNode(5);

    ListNode* res = solution.reverseBetween(l1, 1, 2);

    while (res!=nullptr)
    {
        cout << (res->val) << "->";
        res = res->next;
    }
}