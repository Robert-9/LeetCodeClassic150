/*
    峰值元素是指其值严格大于左右相邻值的元素。
    给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
    你可以假设 nums[-1] = nums[n] = -∞ 。

    你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
*/
#include "../head_bs.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        return findPeakElementHelper(nums, 0, nums.size()-1);
    }
    int findPeakElementHelper(vector<int>& nums, int left, int right){
        if(left >= right) return left;
        int mid = (left+right) / 2;
        
        if(nums[mid] < nums[mid+1]) {
            left = mid+1;
        } else {  // 相邻两数不会相等
            if(mid == 0) {
                return 0;
            }
            if(nums[mid] > nums[mid-1]){
               return mid;
            }
            right = mid-1;
        } 
        return findPeakElementHelper(nums, left, right);
    }
};