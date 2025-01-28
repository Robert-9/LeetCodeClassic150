/*
    给定一个正整数 n，编写一个函数，
    获取一个正整数的二进制形式并返回其二进制表达式中设置位的个数（也被称为汉明重量）。
*/

class Solution {
public:
    int hammingWeight(int n) {
        int result = 0;
        while(n>0) {
            if(n & 1) {
                result++;
            }
            n >>= 1;
        }
        return result;
    }
};