/*
    给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
    测试用例格式：
        简单起见，每个节点的值都和它的索引相同。
            例如，第一个节点值为 1（val = 1），第二个节点值为 2（val = 2），以此类推。该图在测试用例中使用邻接列表表示。
        邻接列表 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。
        给定节点将始终是图中的第一个节点（值为 1）。你必须将 给定节点的拷贝 作为对克隆图的引用返回。


*/
#include "../head_graph.h"


class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> visitedNodes;
        Node* result;
        return cloneGraphHelper(node, visitedNodes);
    }

    Node* cloneGraphHelper(Node* node, unordered_map<int, Node*>& visitedNodes){
        if(node == nullptr || visitedNodes.count(node->val)){
            return nullptr;
        }
        // 新建一个节点, 并加入哈希表中
        Node* curr = new Node(node->val);  
        visitedNodes[node->val] = curr;

        // 为当前节点添加neighbors
        for(int i=0; i<node->neighbors.size(); i++){  // 由于是连通图 故可以通过这样的递归覆盖所有节点
            if(visitedNodes.count(node->neighbors[i]->val)){
                curr->neighbors.push_back(visitedNodes[node->neighbors[i]->val]);
            } else {
                curr->neighbors.push_back(cloneGraphHelper(node->neighbors[i], visitedNodes));
            }
        }
        return curr;
    }
};