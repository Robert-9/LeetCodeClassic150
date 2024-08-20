#include <string>
using namespace std;

class Solution {  
public:  
    int strStr(string haystack, string needle) {  
        if (needle.empty()) return 0;  // 如果 needle 是空字符串，返回 0  
  
        int n = haystack.size();  
        int m = needle.size();  
  
        for (int i = 0; i <= n - m; i++) {  // 遍历 haystack  
            int j = 0;  
            while (j < m && haystack[i + j] == needle[j]) {  
                j++;  
            }  
            if (j == m) {  // 找到匹配的子串  
                return i;  
            }  
        }  
  
        return -1;  // 没有找到匹配项  
    }  
};  