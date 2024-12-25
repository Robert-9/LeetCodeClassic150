/*
    设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
    实现 MinStack 类:
    
    测试已通过，
*/

#include "../stack_head.h"

class MinStack {
public:
    int minVal;
    stack<int> stk;
    stack<int> minStk;
    MinStack() {
    // MinStack() 初始化栈对象。
        minVal = INT_MAX;
        minStk.push(minVal);
    }
    
    void push(int val) {
    // void push(int val) 将元素val推入堆栈。
        if(val <= minVal){
            minVal = val;
            minStk.push(minVal);
        }
        stk.push(val);
    }
    
    void pop() {
    // void pop() 删除堆栈顶部的元素。
        if(stk.top() == minVal){
            minStk.pop();
            minVal = minStk.top();
        }
        stk.pop();
    }
    
    int top() {
    // int top() 检索堆栈中的顶部元素。
        return stk.top();
    }
    
    int getMin() {
    // int getMin() 检索堆栈中的最小元素。
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
