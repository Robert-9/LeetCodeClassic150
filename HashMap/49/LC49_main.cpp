/*
    给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

    字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

*/
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size() <= 1){
            result.push_back(strs);  // 空或为1均直接返回
        } return result;  

        unordered_map<char, int>


    }
};