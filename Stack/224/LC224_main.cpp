/*
    给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

    注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。

    测试已通过，参考题解做法，思路与官方题解类似。
*/

#include "../stack_head.h"
class Solution {
public:
    int calculate(string s) {
        if (s.empty())
            return 0;

        int result = 0;
        int oprator = 1;
        long long num = 0;
        stack<int> opStk;
        opStk.push(oprator);
        for (auto c : s) {
            if (c <= '9' && c >= '0') {
                num = 10*num + (c - '0');
                continue;
            } else{
                if (num != 0) {
                    result += (oprator * num);
                    num = 0;
                }
                if (c == '+') {
                    oprator = opStk.top();
                } else if (c == '-') {
                    oprator = -1 * opStk.top();
                } else if (c == '(') {
                    opStk.push(oprator);
                } else if (c == ')') {
                    opStk.pop();
                } else { // 中途遇到的括号跳过
                    continue;
                }
            }
        }
        if(num != 0){
            result += (oprator * num);
        }
        return result;
    }
};

int main() {
    Solution solu;
    // cout << solu.calculate("1 + 1") << endl;
    cout << solu.calculate(" 2-1 + 2 ") << endl;
    // cout << solu.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    return 0;
}