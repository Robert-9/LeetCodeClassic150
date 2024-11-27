/*
    给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词
。
*/
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sHash;
        unordered_map<char, int> tHash;

        if(s.size() != tHash.size()){
            return false;
        }
        for(int i=0; i<s.size(); i++){
            sHash[s[i]]++;
        }
        for(int i=0; i<t.size(); i++){
            tHash[t[i]]++;
        }
        for(auto pair:sHash){
            if(tHash.find(pair.first)!=tHash.end()){ // 找到了
                if(tHash[pair.first] != pair.second){
                    return false;
                }
            }
        }
        return true;
    }
};