#include "../head_bs.h"


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findFirst(nums, target);
        int end = findLast(nums, target);
        return {start, end};
    }

private:
    // 查找目标值的起始位置
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid - 1; // 等于时仍向左收缩
            } else {
                left = mid + 1;
            }
        }
        // 检查是否找到目标值
        if (left < nums.size() && nums[left] == target) return left;
        return -1;
    }

    // 查找目标值的结束位置
    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] <= target) {
                left = mid + 1; // 等于时仍向右收缩
            } else {
                right = mid - 1;
            }
        }
        // 检查是否找到目标值
        if (right >= 0 && nums[right] == target) return right;
        return -1;
    }
};
