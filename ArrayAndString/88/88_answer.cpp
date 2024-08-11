#include <vector>
using namespace std;

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, const std::vector<int>& nums2,
               int n) {
        int p1 = m - 1;    // 指向nums1中最后一个有效元素
        int p2 = n - 1;    // 指向nums2的最后一个元素
        int p = m + n - 1; // 指向nums1的最后一个位置

        // 从后往前合并
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        // 如果nums2还有剩余元素，拷贝到nums1前面
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p--;
            p2--;
        }
    }
};