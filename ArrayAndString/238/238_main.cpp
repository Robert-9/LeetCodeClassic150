/*
    给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

    题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

    请 不要使用除法，且在 O(n) 时间复杂度内完成此题。
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty()) return nums;

        int len = nums.size();
        vector<int> answer;
        answer[0] = 1;
        for(int i=1; i<len; i++){
            answer[i] = answer[i-1] * nums[i-1];
        }
        for(int i=len-2; i>=0; i--){
            answer[i] = answer[i] * nums[i+1];
        }
        return answer;
    }
};