/*
    给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

    JZ做过  三次反转
*/

#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k>=nums.size()) k = k%nums.size() ;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};