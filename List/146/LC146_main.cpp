/*
    请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。
    实现 LRUCache 类：
    LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
    
    函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/
#include "../list_head.h"


class LRUCache {
public:
    int len=0, cap=0;
    BidirListNode* head;
    BidirListNode* tail;
    unordered_map<int, BidirListNode*> cache;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
    //如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
        if(cache.count(key)){
            // 将操作过的节点移动到头部
            cache[key]->prev->next = cache[key]->next;
            cache[key]->next->prev = cache[key]->prev;
            cache[key]->prev = nullptr;
            cache[key]->next = head;

            head = cache[key];
            // 返回
            return cache[key]->val;
        } else{
            return -1;
        }
    }
    
    void put(int key, int value) {
    // 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。
    // 如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
        if(cache.count(key)){  // 存在则覆盖
            cache[key]->val = value;
        } 
        else{ // 不存在，先加到头部
            cache[key]->val = value;
            cache[key]->prev = nullptr;
            cache[key]->next = head;

            head = cache[key];

            if(len < cap){  // 容量未满 长度增加
                len++;
            }
            else{ // 容量满 从尾部删除 长度不变
                tail
        }
        } 

    }
};



/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */