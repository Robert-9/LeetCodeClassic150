/*
    给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

*/
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int result = s.size()+1;

        unordered_map<char, int> chMap;
        for(int i=0; i<t.size(); i++){
            chMap[t[i]]++;
        }

        int left=0;
        while(left < s.size()){
            if(chMap.find(s[left]) != chMap.end()){
                break;
            }
            left++;
        }
        int right = left;
        int count = 0;

        while(right < s.size()){
            if(chMap.find(s[right]) != chMap.end()){  // 找到了t中的元素
                if(chMap[s[right]] != 0){  // 先判断是否已经出现过 没出现过
                    chMap[s[right]]--;
                    count++;
                } else if(chMap[s[right]] == 0){  //  出现过
                    if()
                }
            }
        }





    }
};