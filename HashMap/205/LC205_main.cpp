/*
    给定两个字符串 s 和 t ，判断它们是否是同构的。
    如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
    每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

    测试已通过！

*/


#include <unordered_map>
#include <string>
using namespace std;

class Solution{
public:
    bool isIsomorphic(string s, string t){
        unordered_map<char, int> sHash;
        unordered_map<char, int> tHash;

        // for(int i=0; i<t.size(); i++){
        //     sHash[t[i]]++;
        // }
        // for(int i=0; i<s.size(); i++){
        //     tHash[s[i]]++;
        // }


        for(int i=0; i<s.size(); i++){
            if(sHash.count(t[i])){  // 如果t的当前字符在s到t的哈希表中已有
                if(sHash[t[i]] == s[i] && tHash[s[i]] == t[i]){  // 能对应上

                } else{
                    return false;
                }
            } else{
                sHash[s[i]] = t[i];
                tHash[s[i]] = s[i];
            }
        }
        return true;

    }
};