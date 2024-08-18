/*
    描述：  
        给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
        不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution{
public: 
    int removeDuplicates(vector<int>& nums){
        if(nums.empty()) return 0;

        int start=0;
        int result=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[start] != nums[i]){
                start = i;
                nums[result++] = nums[i];
            } else{
                if(i-start == 1){
                    nums[result++] = nums[i];
                }
            }
        }
        return result;
    }
};
int main(){
    Solution solution;

    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    int res = solution.removeDuplicates(nums);
    cout << res;
}