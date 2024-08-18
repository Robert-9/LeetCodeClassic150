/*
    描述：
        给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
        返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.empty()) return 0;
        // if(nums.size() == 1) return 1;

        int result = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] != nums[i]){
                nums[result++] = nums[i];
            }
        }
        return result;
    }
};

int main(){
    Solution solution;

    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int res = solution.removeDuplicates(nums);
    cout << res;
}
