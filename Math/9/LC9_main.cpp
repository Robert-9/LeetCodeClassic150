/*
    给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
    回文数
    是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
    例如，121 是回文，而 123 不是

    测试未通过！！！结果不对
    常用正确做法见answer
*/
#include "../head_math.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        int digits = 0;
        int temp = x;
        while(temp > 0) {
            temp /= 10;
            digits++;
        }

        for(int i=1; i<=digits/2; i++) {
            int low = x%10;
            int high = x/pow(10, digits-i);
            if(low != high) {
                return false;
            }
            x -= int(pow(10, digits-i));
            x /= 10;
        }
        return true;
    }
};

int main() {
    Solution solution;
    cout << solution.isPalindrome(121);
}