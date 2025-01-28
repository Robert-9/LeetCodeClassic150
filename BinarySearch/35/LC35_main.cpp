/*
    给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
    如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
    请必须使用时间复杂度为 O(log n) 的算法。

    二分查找
*/
#include "../head_bs.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return searchInsertHelper(nums, target, 0, nums.size()-1);
    }
    int searchInsertHelper(vector<int>& nums, int target, int left, int right){
        if(left > right) return left;
        int mid = (left + right)/2;
        if(nums[mid] == target) {
            return mid;
        }
        if(nums[mid] > target) {
            right = mid-1;
        } else {
            left = mid+1;
        }
        return searchInsertHelper(nums, target, left, right);
    }   
};