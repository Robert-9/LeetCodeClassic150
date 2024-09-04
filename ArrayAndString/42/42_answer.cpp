/*
    当 height[left] <= height[right] 时：
        此时，left_max 是左边指针经过的最高的柱子高度，它保证了在 left 位置能形成的“水池”的右边界一定不低于 height[right]。
        也就是说，如果左侧高度 height[left] 小于 left_max，那么在 left 位置能够积累的雨水的深度就是 left_max - height[left]，
        而不需要担心右边更小的柱子，因为我们已经确定 右边的界限由 height[right] 决定，而 height[right] 不会比 height[left] 更小。
        这样的操作是安全且正确的，因为任何中间更小的柱子不会影响已经确认的左边界的雨水积累。
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int result = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    result += left_max - height[left];
                }
                left++;
            } 
            else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    result += right_max - height[right];
                }
                right--;
            }
        }

        return result;
    }
};
