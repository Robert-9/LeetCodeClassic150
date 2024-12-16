/*
    给定一个  无重复元素 的 有序 整数数组 nums 。
    返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。
    也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 nums 的数字 x 。

    双指针法
    测试已通过
    关键：
       用 (nums[i] != (nums[i - 1]) + 1 而不是 (nums[i] - (nums[i - 1]) == 1
       避免前后两数相差太大（一正一负），直接相减而导致溢出！
*/
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int len = nums.size();
        if (len == 0) {
            return result;
        } else if (len == 1) {
            result.push_back(to_string(nums[0]));
            return result;
        }
        // 长度大于等于2
        int start = 0, end = 0;
        for (int i = 1; i < len; i++) {
            if ((nums[i] != (nums[i - 1]) + 1)) { // 如果不连续
                addRegion(nums[start], nums[end], result);
                start = end + 1;
                end = start;
            } else {
                end += 1;
            }
            if(i == len - 1){
                addRegion(nums[start], nums[end], result);
            }
        }
        return result;
    }

private:
    void addRegion(int startVal, int endVal, vector<string>& result) {
        if (startVal < endVal) {
            string str = to_string(startVal) + "->" + to_string(endVal);
            result.push_back(str);
        } else {
            result.push_back(to_string(startVal));
        }
    }
};