#include <string>

using namespace std;

class Solution{
public:
    bool isSubsequence(string s, string t){
        int sIndex=0, tIndex=0;
        
        while(sIndex < s.size() && tIndex < t.size()){
            if(s[sIndex] == t[tIndex]){
                sIndex++;
                tIndex++;
            } else{
                tIndex++;
            }
        }
        if(sIndex == s.size()){
            return true;
        } else{
            return false;
        }
    }

};