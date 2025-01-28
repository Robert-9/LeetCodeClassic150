#include "../head_bs.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return findPeakElementHelper(nums, 0, nums.size() - 1);
    }

private:
    int findPeakElementHelper(vector<int>& nums, int left, int right) {
        if (left == right) return left; // 递归终止，找到峰值

        int mid = (left + right) / 2;
        
        if (nums[mid] < nums[mid + 1]) {  // 此时mid一定不是峰值，故区间从mid+1开始 
            return findPeakElementHelper(nums, mid + 1, right);
        } else {  // mid可能是峰值
            return findPeakElementHelper(nums, left, mid);
        }
    }
};
