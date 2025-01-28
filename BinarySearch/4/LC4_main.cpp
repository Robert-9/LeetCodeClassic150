/*
    给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
    请你找出并返回这两个正序数组的 中位数 。
    算法的时间复杂度应该为 O(log (m+n)) 。
*/
#include "../head_bs.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int idx = (m+n)/2;

        if((m+n)%2) {  // 奇数直接返回
            return findKth(nums1, 0, nums2, 0, idx);
        } else {  // 偶数返回两数平均值
            double res1 = findKth(nums1, 0, nums2, 0, idx);
            double res2 = findKth(nums1, 0, nums2, 0, idx+1);
            return (res1+res2)/2;
        }
    }

    double findKth(vector<int>& nums1, int curr1, vector<int>& nums2, int curr2, int k) {  // 返回第k个数的下标
        if(k == 1) {
            return min(nums1[curr1], nums2[curr2]);
        } else if(curr1 >= nums1.size()-1) {
            return nums2[curr2+k];
        } else if(curr2 >= nums2.size()-1) {
            return nums1[curr1+k];
        }

        int binary = k/2;
        if((curr1+binary) > nums1.size()) {
            if(nums1.back() <= nums2[curr2+binary-1]) {
                k = k - (nums1.size()-1 - curr1);
                curr1 = nums1.size()-1;
            } else if(nums1.back() > nums2[curr2+binary-1]) {
                curr2 += binary;
                k = k - binary;
            } 
        } else if((curr2+binary) > nums2.size()) {
            if(nums1[curr1+binary-1] <= nums2.back()) {
                curr1 += binary;
                k = k - binary;
            } else if(nums1[curr1+binary-1] > nums2.back()) {
                k = k - (nums2.size()-1 - curr2);
                curr2 = nums2.size()-1;
            } 
        }
        else {
            if(nums1[curr1+binary-1] <= nums2[curr2+binary-1]) {
                curr1 += binary;
            } else if(nums1[curr1+binary-1] > nums2[curr2+binary-1]) {
                curr2 += binary;
            } 
            k = k - binary;  // 减去已经去除的
        }
        return findKth(nums1, curr1, nums2, curr2, k);
    }
};