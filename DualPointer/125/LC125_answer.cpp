#include <string>

using namespace std;

class Solution {  
public:  
    bool isPalindrome(string s) {  
        int left = 0, right = s.size() - 1;  
  
        while (left < right) {  
            // 跳过非字母数字字符  
            while (left < right && !isalnum(s[left])) {  
                left++;  
            }  
            while (left < right && !isalnum(s[right])) {  
                right--;  
            }  
  
            // 比较字符，忽略大小写  
            if (tolower(s[left]) != tolower(s[right])) {  
                return false;  
            }  
  
            left++;  
            right--;  
        }  
  
        return true;  
    }  
};  