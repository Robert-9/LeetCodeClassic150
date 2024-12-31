/*
    给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
    如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

    对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
    如果 s 中存在这样的子串，我们保证它是唯一的答案。
*/
#include "head_sw.h"
using namespace std;

class Solution {
public:
    int minLen = INT_MAX;  // 最小长度初始化不能为0！！！！
    string result;
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        int left=0, right=0;
        int charCur=0;
        
        unordered_map<char,int> tMap;
        // 创建键，并给值赋初值0
        for(auto c:t){
            tMap[c] = 0;
        }
        while(right<s.size()){  // 右指针超限则结束
            if(tMap.count(s[right])){  // 如果 在t里面：哈希表里对应的值+1，哈希表值为1代表第一次出现则出现过的字符数+1
                tMap[s[right]] += 1;
                if(tMap[s[right]] == 1){  //+1后等于1代表该字符第一次出现
                    charCur += 1;
                }
            }
            if(right<s.size()){  // 右指针右移
                right++;
            }
            // 当前滑窗覆盖了所有t
            if (charCur == t.size()){
                calResult(left, right, s);
                while(left<right){  // 左指针右移 
                    left++;
                    if (tMap.count(s[left])){  //如果左指针的值在t中，则对应的哈希表值-1
                        tMap[s[left]]--;
                        if (tMap[s[left]] == 0){  // 值为1代表再左指针右移后，该字符的数量不满足要求
                            charCur--;
                            break;
                        }
                    }
                }
            }
            
        }
        return result;
    }
private:
    void calResult(int left, int right, string& s){
        int len = right - left + 1;
        if(len<minLen){  // 更新最小长度和最小子串
            minLen = len;
            result = {s.begin()+left, s.begin()+right};
        }
    }
};

int main(){
    Solution s;
    string str = "ADOBECODEBANC";
    string t = "ABC";
    cout << s.minWindow(str, t) << endl;
    return 0;
}