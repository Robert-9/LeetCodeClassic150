/*
    给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。

    这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。
*/

#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> pHash;
        unordered_map<string, char> sHash;

        int indexS = 0;
        int indexP = 0;
        string word;
        int numOfWords = 0;

        while(indexP<pattern.size() && indexS<s.size()){
            while(s[indexS++] != ' '){  // 提取出一个单词
                word += s[indexS-1];
            }
            if(pHash.find(pattern[indexP])!=pHash.end() || sHash.find(word)!=sHash.end()){
                if(pHash[pattern[indexP]] != word || sHash[word] != pattern[indexP]){
                    return false;
                    // break;
                }
            } else{
                pHash[pattern[indexP]] = word;
                sHash[word] = pattern[indexP];
            }
            
            word.clear();
            if(indexS==s.size()){
                break;
            }

        }
        // if(indexS < s.size()){
        //     return false;
        // }
        return true;
        
    }
};