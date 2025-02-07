/*
    给定一个整数 n ，返回 n! 结果中尾随零的数量。
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int mul_5 = 0;
        while(n > 0) {
            n /= 5;
            mul_5 += n;
        }
        return mul_5;
    }
};