/*
    事实上，由于输入x的int类型限制了其极值，
    上界right可以进一步缩小为 46340 而不是x.
*/

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x, result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long long)mid * mid <= x) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};
