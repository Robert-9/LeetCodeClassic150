#include "../head_bs.h"


class Solution {  
public:  
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {  
        int m = nums1.size(), n = nums2.size();  
        int total = m + n;  

        if (total % 2 == 1) {  
            return findKth(nums1, 0, nums2, 0, total / 2 + 1);  
        } else {  
            double res1 = findKth(nums1, 0, nums2, 0, total / 2);  
            double res2 = findKth(nums1, 0, nums2, 0, total / 2 + 1);  
            return (res1 + res2) / 2.0;  
        }
    }  
  
private:  
    double findKth(vector<int>& nums1, int curr1, vector<int>& nums2, int curr2, int k) {  
        // 如果 nums1 用完了，直接返回 nums2 的第 k 个元素  
        if (curr1 >= nums1.size()) return nums2[curr2 + k - 1];  
        // 如果 nums2 用完了，直接返回 nums1 的第 k 个元素  
        if (curr2 >= nums2.size()) return nums1[curr1 + k - 1];  
        // 如果 k == 1，返回当前最小的元素  
        if (k == 1) return min(nums1[curr1], nums2[curr2]);  
  
        // 获取 nums1 和 nums2 中第 k/2 个元素的值，若超出范围则设为无穷大  
        int mid1 = (curr1 + k / 2 - 1 < nums1.size()) ? nums1[curr1 + k / 2 - 1] : INT_MAX;  
        int mid2 = (curr2 + k / 2 - 1 < nums2.size()) ? nums2[curr2 + k / 2 - 1] : INT_MAX;  
  
        // 比较两数组的第 k/2 个元素  
        if (mid1 < mid2) {  
            return findKth(nums1, curr1 + k / 2, nums2, curr2, k - k / 2);  
        } else {  
            return findKth(nums1, curr1, nums2, curr2 + k / 2, k - k / 2);  
        }  
    }  
};  