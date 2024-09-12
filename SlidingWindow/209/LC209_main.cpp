/*
    给定一个含有 n 个正整数的数组和一个正整数 target 。
    找出该数组中满足其总和大于等于 target 的长度最小的子数组
    [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
*/

#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int start = 0;
        int end = 0;
        int curSum = nums[0];
        int result = 0;  //先将长度设为总长
        int curWinLenth = 1;
        int minWinLenth = len;
        while(start <= end){
            if(curSum < target){
                if(end < len-1){
                    end++;
                    curSum += nums[end];
                    curWinLenth++;
                } else{
                    break;
                }
            } else if(curSum >= target){
                if(curWinLenth < minWinLenth){
                    minWinLenth = curWinLenth;
                    result = minWinLenth;
                }
                if(start < end){
                    curSum -= nums[start];
                    start++;
                    curWinLenth--;
                }
                else{
                    result = 1;
                    break;
                }
            }
        }   
        return result;
    }
};

int main(){
    Solution solution;

    vector<int> input {1,2,3,4, 5};
    solution.minSubArrayLen(15, input);
}