/*
    给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
    如果可以，返回 true ；否则返回 false 。

    magazine 中的每个字符只能在 ransomNote 中使用一次
*/
#include <unordered_map>
#include <string>
using namespace std;

class Solution{
public:
    bool canConstruct(string ransomNote, string magazine){
        // unordered_map<char, int> rnHash;
        unordered_map<char, int> maHash;

        // for(int i=0; i<ransomNote.size(); i++){
        //     rnHash[ransomNote[i]]++;
        // }
        for(int i=0; i<magazine.size(); i++){
            maHash[magazine[i]]++;
        }
        for(int i=0; i<ransomNote.size(); i++){
            if(maHash.count(ransomNote[i])){  // 在magzine里面能找到rn的全部字符
                maHash[ransomNote[i]]--;
                if(maHash[ransomNote[i]] < 0){
                    return false;
                }
            } else{
                return false;
            }
        }
        return true;

    }
};