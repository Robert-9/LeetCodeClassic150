#include "../stack_head.h"

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty()) return 0;

        stack<int> stk; // 栈中存储整数
        for (const string& token : tokens) {
            // 判断是否是运算符
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // 弹出栈顶的两个数字
                int num1 = stk.top(); stk.pop();
                int num2 = stk.top(); stk.pop();

                // 根据运算符进行计算
                if (token == "+") {
                    stk.push(num2 + num1);
                } else if (token == "-") {
                    stk.push(num2 - num1);
                } else if (token == "*") {
                    stk.push(num2 * num1);
                } else if (token == "/") {
                    stk.push(num2 / num1);
                }
            } else {
                // 如果是数字，直接压栈
                stk.push(stoi(token));
            }
        }

        // 栈中最后剩下的就是结果
        return stk.top();
    }
};