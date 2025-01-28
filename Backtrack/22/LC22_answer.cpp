#include "../head_backtrack.h"
class Solution {  
public:  
    vector<string> generateParenthesis(int n) {  
        vector<string> result;  
        string curr;  
        generateParenthesisHelper(n, 0, 0, curr, result);  
        return result;  
    }  
  
    void generateParenthesisHelper(int n, int leftNum, int rightNum, string& curr, vector<string>& result) {  
        if (curr.size() == 2 * n) {  
            result.push_back(curr);  
            return;  
        }  
  
        // 尝试添加左括号  
        if (leftNum < n) {  
            curr.push_back('(');  
            generateParenthesisHelper(n, leftNum + 1, rightNum, curr, result);  
            curr.pop_back(); // 回溯  
        }  
  
        // 尝试添加右括号  
        if (rightNum < leftNum) {  
            curr.push_back(')');  
            generateParenthesisHelper(n, leftNum, rightNum + 1, curr, result);  
            curr.pop_back(); // 回溯  
        }  
    }  
};  