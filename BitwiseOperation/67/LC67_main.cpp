/*
    给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
*/
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        // 确保 a 和 b 长度一致，短的前面补 '0'
        int lenA = a.size(), lenB = b.size();
        if (lenA < lenB) {
            a.insert(0, lenB - lenA, '0');
        } else if (lenA > lenB) {
            b.insert(0, lenA - lenB, '0');
        }
        
        string result;
        char carry = '0'; // 进位
        
        // 从低位到高位逐位相加
        for (int i = a.size() - 1; i >= 0; --i) {
            int sum = (a[i] - '0') + (b[i] - '0') + (carry - '0'); // 按位求和
            result.push_back((sum % 2) + '0'); // 当前位结果
            carry = (sum / 2) + '0';           // 更新进位
        }
        
        // 如果最后还有进位，添加到结果中
        if (carry == '1') {
            result.push_back('1');
        }
        
        // 结果需要反转，因为我们是从低位开始加的
        reverse(result.begin(), result.end());
        return result;
    }
};
