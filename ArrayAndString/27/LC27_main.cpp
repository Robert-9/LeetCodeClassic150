/*
    给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。
    元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。

    测试未通过
    想用两个索引，一个从前往后找val一个从后往前找非val，然后交换二者的位置
    但对于特殊情况的处理总是报错。入
*/

#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0, right=nums.size()-1;
        int k=0;
        while(left<=right){
            while(nums[left]!=val && left<=right){
                left++;
                k++;
            }
            while(nums[right] == val && left<=right){
                right--;
            }
            swap(nums[left++], nums[right--]);
        }
        return k;
    }
};


int main(){
    Solution solution;
    vector<int> nums1 = {1};
    solution.removeElement(nums1, 1);
}