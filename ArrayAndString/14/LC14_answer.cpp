#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; 

        for (int i = 0; i < strs[0].size(); i++) {  // 以第一个字符串为基准，逐渐取字符出来
            char currentChar = strs[0][i];
            for (int j = 1; j < strs.size(); j++) { // 遍历每个字符的列
                if (i >= strs[j].size() || strs[j][i] != currentChar) { // 前字符不匹配 或 超出当前字符串长度
                    return strs[0].substr(0, i);
                }
            }
        }
        // 如果for循环遍历完了 返回第一个字符串的内容
        return strs[0];
    }
};
