/*
    整数数组 nums 按升序排列，数组中的值 互不相同 。
    在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
    例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
    给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
    你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

    测试已通过
*/
#include "../head_bs.h"

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = searchHelper(nums, target);

        int left = 0, right = idx-1;

        return searchHelper(nums, target);
    }
    int searchHelper(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left<right && right-left != 1){
            int mid = (left + right) / 2;
            if(nums[left] < nums[mid]) {
                left = mid;
            } else {  // 无重复数字
                right = mid;
            }
        }
        int idx = right;
        if(idx!=0){
            int res = findTarget(nums, target, 0, idx-1);
            if (res != -1) return res;
        }
        int res = findTarget(nums, target, idx, nums.size()-1);
        if (res != -1) return res;
        return -1;
    }
    int findTarget(vector<int>& nums, int target, int left, int right) {
        if(target < nums[left] || target > nums[right]) return -1;
        if(left == right) {
            if(nums[left] == target) return left;
            else return -1;
        }
        int mid = (left+right)/2;

        if (nums[mid] < target) {
            left = mid+1;
        } else if(nums[mid] > target) {
            right = mid-1;
        } else 
            return mid;
        return findTarget(nums, target, left, right);
    }
};