class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; // 负数不是回文数

        int original = x;
        long reversed = 0; // 使用 long 防止反转后溢出

        // 反转整数
        while (x != 0) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // 比较反转后的数和原数
        return (original == reversed);
    }
};
