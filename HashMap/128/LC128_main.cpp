/*
    给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
    请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

    unordered_set(哈希表)：插入、查找的复杂度均为O(1)
*/
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        int maxLenth = 0;
        int tempLenth = 0;
        for(int i=0; i<nums.size(); i++){
            // if(numSet.find(nums[i]) == numSet.end()){
                numSet.insert(nums[i]);
            // }
        }
        for(auto element: numSet){ // 外层O(n)，内层O(1)  （对哈希表的查找时间复杂度为常数）
            if(numSet.find(element-1) != numSet.end()){ // 比当前元素小1的元素在set中，即当前元素不可作为起始，则break
                break;
            }
            while (numSet.find(element) != numSet.end()) // 当前元素可作为起始，通过检查+1是否在set中判断序列是否结束
            {
                tempLenth++;
                element++;
            }
            if(tempLenth>maxLenth){
                maxLenth = tempLenth;
            }
            tempLenth = 0;
        }
        return maxLenth;
    }
};

int main(){
    Solution solution;
    vector<int> input = {9,1,4,7,3,-1,0,5,8,-1,6};
    cout << solution.longestConsecutive(input) << endl;
}