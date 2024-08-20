/*
    给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
    如果 needle 不是 haystack 的一部分，则返回  -1 。
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int indexHay=0;
        int res = 0;
        while(indexHay < haystack.size()){
            if(haystack[indexHay++] == needle[0]){
                res = indexHay-1;
                int indexNeed=0;
                while(++indexNeed < needle.size()){
                    if(haystack[indexHay++] != needle[indexNeed]){
                        break;
                    }
                }
                if(indexNeed == needle.size()){
                    return res;
                }
            }
            indexHay = res+1;
            // indexHay++;
        }

        return -1;
    }
};


int main(){
    Solution solution;
    string haystack = "mississippi";
    string needle = "issip";
    int res = solution.strStr(haystack, needle);
    cout<< res;
}