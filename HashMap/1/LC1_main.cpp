#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
/*
    测试未通过
*/
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        vector<int> result;
        int res1=-1;
        if(!nums.empty()){
            for(int i=0; i<nums.size(); i++){
                numMap[nums[i]]++;
            }
        }
        for(auto pair:numMap){
            int diff = target - pair.first;
            if(diff != pair.first){
                if(numMap[diff] > 0){
                    res1 = pair.first;
                    break;
                }
            }
            else if(pair.second>1){
                res1 = pair.first;
                break;
            }

        }
        int res2 = target - res1;
        for(int j=0; j<nums.size(); j++){
            if(nums[j] == res1 || nums[j] == res2){
                result.push_back(j);
            }
            if(result.size() == 2){
                break;
            }
        }
        return result;
        
    }
};


class Solution2 {
    /*  
        边查边找
    */
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(numMap.find(diff) != numMap.end()){
                return {numMap[diff], i};
            }
            numMap[nums[i]] = i;
        }
        return {};
        
    }
};


int main()
{
    Solution solution;
    vector<int> nums = {0, 0, 4, 3};
    int target = 0;
    vector<int> res = solution.twoSum(nums, target);
    for(const auto& val:res){
        cout << val << " ";
    }
    return 0;
}
