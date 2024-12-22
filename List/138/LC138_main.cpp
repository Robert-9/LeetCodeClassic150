/*
    给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。

    构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
    新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
    复制链表中的指针都不应指向原链表中的节点 。

    第一遍没做出来！
*/

#include "../list_head.h"

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummyResHead = new Node(0);
        Node* pResCur = dummyResHead;
        Node* pInCur = head;
        unordered_map<Node*, Node*> randNodeMap;

        while (pInCur != nullptr) { // 将next深复制，创建节点
            pResCur->next = new Node(pInCur->val);

            randNodeMap[pInCur] = pResCur->next;
            pInCur = pInCur->next;
            pResCur = pResCur->next;
        }
        pInCur = head;
        pResCur = dummyResHead->next;
        while (pInCur != nullptr) {
            if (pInCur->random) {
                // 输入链表(pInCur)的random也是一个输入节点(pInCur),其在map中会对应一个相应位置的返回节点(pReCur)
                // 该节点即为当前返回节点应该对应的random节点
                pResCur->random = randNodeMap[pInCur->random];  
            } 
            else {
                pResCur->random = nullptr; // 原节点的random为空
            }
            pInCur = pInCur->next;
            pResCur = pResCur->next;
        }
        return dummyResHead->next;
    }
};