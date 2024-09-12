/*
    给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串的长度。

    测试已通过
*/
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 1) { return 1;}
        int start=0;
        unordered_map<char, int> charMap;
        int maxLen = 0;

        for(int i=0; i<s.size(); i++){
            auto it = charMap.find(s[i]);
            if(it != charMap.end() && start <= charMap[s[i]]){  // 必须要start在重复字符之前，即重复的字符在当前滑窗内
                start = charMap[s[i]]+1;  // 注意这里是重复字符的下一个
            }
            charMap[s[i]] = i;
            maxLen = max(maxLen, i+1-start);
        }
        return maxLen;
    }
};



int main(){
    Solution solution;

    string input = "abcabcbb" ;
    solution.lengthOfLongestSubstring(input);
}