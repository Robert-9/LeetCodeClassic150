/*
    描述：
        给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。
        判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。

    想用递归写，没写对
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    bool canJumpHelper(vector<int>& nums, int index) {
        if(index == 0) return true;

        bool res = false;
        for(int i=index-1; i>0; i--){
            if(nums[i] == index-i){
                return canJumpHelper(nums, i);
            }
        }
        return res;
    }
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return false;

        return canJumpHelper(nums, nums.size()-1);
    }
};

int main(){
    Solution solution;
    vector<int> nums = {2,3,1,1,4};

    bool res = solution.canJump(nums);

    cout<< res;
}