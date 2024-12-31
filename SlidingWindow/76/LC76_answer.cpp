#include "../head_sw.h"

class Solution {
public:
    int minLen = INT_MAX;  // 初始化为最大值
    string result;
    int resultL=0, resultR=0;

    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        int left = 0, right = 0;
        int charCur = 0;

        unordered_map<char, int> tMap;
        // 创建键，值保存字符出现个数
        for (auto c : t) {
            tMap[c]++;
        }

        while (right < s.size()) {
            if (tMap.count(s[right])) {  // 如果字符在t中，哈希表中相应的字符计数减1
                tMap[s[right]]--;
                if (tMap[s[right]] == 0) {  // 该字符满足要求
                    charCur++;
                }
            }
            right++;  // 右指针右移

            // 当前滑窗覆盖了所有t
            while (charCur == tMap.size()) {
                calResult(left, right, s);
                if (tMap.count(s[left])) {  // 如果左指针的值在t中
                    tMap[s[left]]++;
                    if (tMap[s[left]] > 0) {
                        charCur--;  // 不为0，滑窗中失去一个符合要求的字符
                    }
                }
                left++;  // 左指针右移
            }
        }

        return {s.begin()+resultL, s.begin()+resultR};
    }

private:
    void calResult(int left, int right, string &s) {
        int len = right - left;
        if (len < minLen) {  // 更新最小长度和最小子串
            minLen = len;
            // result =  {s.begin()+left, s.begin()+right};  // 使用substr直接截取子串
            resultL = left;
            resultR = right;
        }
    }
};


