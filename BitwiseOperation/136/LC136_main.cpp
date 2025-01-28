/*
    给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，
    其余每个元素均出现  两次 。    找出那个只出现了一次的元素。
    你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

    按位异或。相同的数字异或为0.
*/

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i=1; i<nums.size(); i++){
            res ^= nums[i];
        }
        return res;
    }
};