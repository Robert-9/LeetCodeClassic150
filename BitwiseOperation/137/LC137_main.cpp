/*
    给你一个整数数组 nums ，除某个元素仅出现 一次 外，
    其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

    你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。
*/

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0; i<32; i++) {
            int total = 0;
            for(auto num : nums) {
                total += num>>i & 1;
            }
            if(total%3) {
                result |= 1<<i;
            }
        }
        return result;
    }
};