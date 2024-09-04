/*
    如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。

    字母和数字 都属于字母数字字符。

    给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
*/

#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return false;
        int len = s.size();
        vector<char> str;

        for (int i = 0; i < len; i++) {
            if (islower(s[i]) || isdigit(s[i])) {
                str.push_back(s[i]);
            } else if (isupper(s[i])) {
                str.push_back(tolower(s[i]));
            }
        }
        int left = 0, right = str.size() - 1;
        while (left <= right) {
            if (str[left] != str[right]) {
                break;
            } else{
                left++;
                right--;
            }
        }

        if (left <= right) {
            return 0;
        } else {
            return 1;
        }
    }
};