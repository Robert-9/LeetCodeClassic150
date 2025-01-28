/*
    给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
    如果数组中不存在目标值 target，返回 [-1, -1]。

    你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
*/

#include "../head_bs.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return searchRangeHelper(nums, target, 0, nums.size()-1);
    }
    vector<int> searchRangeHelper(vector<int>& nums, int target, int left, int right) {
        if(left >= right) {
            if(left>=0 && left<nums.size() && nums[left] == target) 
                return {left, left};
            else 
                return {-1, -1};
        }

        int mid = (left+right)/2;

        if (nums[mid] > target) {
            right = mid-1;
        } else if (nums[mid] < target) {
            left = mid+1;
        } else {
            return getIndex(nums, target, mid);
        }
        return searchRangeHelper(nums, target, left,right);
    }
    vector<int> getIndex(vector<int>& nums, int target, int mid) {
        vector<int> result;
        int start=-1, end=-1;
        for(int i=mid; i<nums.size(); i++) {
            if(nums[i] != target) {
                end = i-1;
                break;
            }
        }
        if (end == -1) end = nums.size()-1;
        for(int i=mid; i>=0; i--) {
            if(nums[i] != target) {
                start = i+1;
                break;
            }
        }
        if (start == -1) start = 0;

        result.push_back(start);
        result.push_back(end);
        return result;
    }
};