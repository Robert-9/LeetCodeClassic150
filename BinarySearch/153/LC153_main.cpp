#include "../head_bs.h"

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.front() < nums.back()) return nums.front();
        return findMinHelper(nums);
    }
    int findMinHelper(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left<right && right-left != 1){
            int mid = (left + right) / 2;
            if(nums[left] < nums[mid]) {
                left = mid;
            } else {  // 无重复数字
                right = mid;
            }
        }
        return nums[right];
    }
};