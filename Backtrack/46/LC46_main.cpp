/*
    给定一个不含重复数字的数组 nums ，返回其 所有 可能的全排列 。
    你可以 按任意顺序 返回答案。

    示例 ：
    输入：nums = [1,2,3]
    输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

#include "../head_backtrack.h"


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.empty()) return result;

        unordered_map<int ,bool> isUsed;
        for(auto num : nums){
            isUsed[num] = false;
        }
        vector<int> vec;
        permuteHelper(nums, vec, result, isUsed);
        return result;
    }
    void permuteHelper(vector<int>& nums, vector<int>& curr, vector<vector<int>>& result, unordered_map<int ,bool>& isUsed) {
        if(curr.size() == nums.size()){
            result.push_back(curr);
            return ;
        }

        for(auto num : nums){
            if(isUsed[num]){
                continue;
            } else {
                curr.push_back(num);
                isUsed[num] = true;
                permuteHelper(nums, curr, result, isUsed);
                isUsed[num] = false;
                curr.pop_back();
            }
        }
    }
};

void main(){
    vector<int> input = {1, 2, 3};
    Solution solution;
    vector<vector<int>> outputs = solution.permute(input);

    for(auto output : outputs){
        for(auto n :output){
            cout << n << ',';
        }
        cout << endl;
    }
}