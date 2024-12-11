/*
    给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

    字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

*/
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size() <= 1){
            result.push_back(strs);  // 空或为1均直接返回
            return result;
        } 
          

        vector<unordered_map<char, int>> mapVec;
        for(int i=0; i<strs.size(); i++){  
            unordered_map<char, int> chMap;
            for(int j=0; j<strs[i].size(); j++){
                chMap[strs[i][j]]++;
            }
            // 接下来找对应单词的map是否出现过
            auto iter = find(mapVec.begin(), mapVec.end(), chMap);
            int index = 0;
            if(iter == mapVec.end()){ // 没出现过
                index = mapVec.size();
                mapVec.push_back(chMap);
            }
            else{// 根据map在mapVec里的索引向result插入
                index = distance(mapVec.begin(), iter);
            }
            result[index].push_back(strs[i]);
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);
    for(auto vec: result){
        for(auto str: vec){
            cout<< "str is " << str << endl;
        }
    }
}