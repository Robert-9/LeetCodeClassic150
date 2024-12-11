#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if (strs.size() <= 1) {
            result.push_back(strs);  // 空或为1均直接返回
            return result;
        }

        // 使用哈希表将排序后的字符串作为key进行分组
        unordered_map<string, vector<string>> anagramGroups;
        
        for (const string& str : strs) {
            string sortedStr = str;  // 将字符串复制出来
            sort(sortedStr.begin(), sortedStr.end());  // 排序
            anagramGroups[sortedStr].push_back(str);  // 将原字符串放入对应分组
        }

        // 将结果从哈希表中提取出来
        for (const auto& group : anagramGroups) {
            result.push_back(group.second);
        }
        
        return result;
    }
};
