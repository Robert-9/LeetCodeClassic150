/*
    数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

    测试已通过
*/
#include "../head_backtrack.h"


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHelper(n, 1, 0, "(", result);
        return result;
    }
    void generateParenthesisHelper(int n, int leftNum, int rightNum,string curr, vector<string>& result) {
        if(curr.size() == 2*n) {
            result.push_back(curr);
            return ;
        }
        if(leftNum<n  && leftNum>=rightNum){

            generateParenthesisHelper(n, leftNum+1, rightNum, curr+'(', result);
        }
        if(rightNum < n){
            generateParenthesisHelper(n, leftNum, rightNum+1, curr+')', result);
        }
    }
};