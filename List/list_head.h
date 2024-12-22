#include <vector>
#include <unordered_map>
#include <queue>

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 138用了
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


//
class BidirListNode{
public:
    int val;
    BidirListNode* prev;
    BidirListNode* next;

    BidirListNode(int _val){
        val = _val;
        prev = nullptr;
        next = nullptr;
    }
};

/*
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
*/