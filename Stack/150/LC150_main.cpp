/*
    给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。

    请你计算该表达式。返回一个表示表达式值的整数。

    注意：

    有效的算符为 '+'、'-'、'*' 和 '/' 。
    每个操作数（运算对象）都可以是一个整数或者另一个表达式。
    两个整数之间的除法总是 向零截断 。
    表达式中不含除零运算。
    输入是一个根据逆波兰表示法表示的算术表达式。
    答案及所有中间计算结果可以用 32 位 整数表示。


    本题的关键是要将每次计算的结果压入堆栈，下一次再弹出来进行计算
*/

#include "../stack_head.h"


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.empty())
            return 0;
        if(tokens.size() == 1){
            return stoi(tokens[0]);
        }
        stack<string> stk;
        int result = 0;
        int num1 = 0;
        int num2 = 0;
        unordered_set<string> oprator = {"+", "-", "*", "/"};
        for (auto element : tokens) {
            if (oprator.count(element)) {

                num1 = stoi(stk.top());
                stk.pop();
                num2 = stoi(stk.top());
                stk.pop();

                if (element == "+") {
                    result = num2 + num1;
                } else if (element == "-") {
                    result = num2 - num1;
                } else if (element == "/") {
                    result = num2 / num1;
                } else if (element == "*") {
                    result = num2 * num1;
                }
                stk.push(to_string(result));
            } else {
                stk.push(element);
            }
        }
        return result;
    }
};