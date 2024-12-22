struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);  // 哑节点，简化链表操作
        ListNode* cur = dummyHead;
        int carry = 0;  // 进位
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;  // 先加上之前的进位
            if (l1 != nullptr) {
                sum += l1->val;  // 加上 l1 当前位的值
                l1 = l1->next;  // 移动到 l1 的下一个节点
            }
            if (l2 != nullptr) {
                sum += l2->val;  // 加上 l2 当前位的值
                l2 = l2->next;  // 移动到 l2 的下一个节点
            }
            
            carry = sum / 10;  // 计算进位
            cur->next = new ListNode(sum % 10);  // 创建当前位的节点
            cur = cur->next;  // 移动 cur 指针
        }
        
        return dummyHead->next;  // 返回头节点的下一个节点
    }
};
