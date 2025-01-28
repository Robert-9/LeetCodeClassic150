#include "../head_bs.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.front() < nums.back()) return nums.front(); // 未旋转的情况

        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;

            if (nums[mid] > nums[right]) {
                // 最小值一定在右侧
                left = mid + 1;
            } else {
                // 最小值可能是 mid 或在左侧
                right = mid;
            }
        }

        return nums[left]; // 最小值
    }
};
