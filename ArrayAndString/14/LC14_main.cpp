/*
    编写一个函数来查找字符串数组中的最长公共前缀。
    如果不存在公共前缀，返回空字符串 ""。

    测试已通过！一开始没有每次将index置0，且没有(++index < strs.size()) 而是 index < strs.size() 再在while里面去index++，这会导致数组越界。
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        
        int minLen = strs[0].size();

        for(int i=0; i<strs.size(); i++){
            if(strs[i].size()<minLen){
                minLen = strs[i].size();
            }
        }

        for (int i = 0; i < minLen ; i++) {
            int index = 0;
            while (++index < strs.size()) {
                if (strs[index - 1][i] == strs[index][i]) {
                    continue;
                } else {
                    break;
                }
            }
            if (index == strs.size()) {
                result += strs[0][i];
            } else{
                break;
            }
        }

        return result;
    }
};