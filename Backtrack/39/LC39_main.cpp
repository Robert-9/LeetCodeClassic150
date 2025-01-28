/*
    给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
    找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。
    你可以按 任意顺序 返回这些组合。
    candidates 中的 同一个 数字可以 无限制重复被选取 。
    如果至少一个数字的被选数量不同，则两种组合是不同的。 

    测试已通过，可改进的点包括：
        从累加改为对target做减法，最后判断是否等于0，可省去保存当前和的num;
        不用bool类型做返回值，不通过返回值剪枝。只在递归终止条件 currSum == target 下直接将 path 添加到结果中。则不用排序
*/
#include "../head_backtrack.h"


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.empty()) return result;

        int n=0;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        combinationSumHelper(candidates, target, n, 0, path, result);
        return result;
    }
    bool combinationSumHelper(vector<int>& candidates, int& target, int& currSum, int startIdx, vector<int>& path, vector<vector<int>>& result) {
        if(currSum > target){
            return true;
        } else if(currSum == target){
            result.push_back(path);
            return true;
        }
        for(int i=startIdx; i<candidates.size(); i++){
            int num = candidates[i];
            currSum += num;
            path.push_back(num);
            bool res = combinationSumHelper(candidates, target, currSum, i, path, result);           
            currSum -= num;
            path.pop_back();
            if(res){
                break;                
            }               
        }
        return false;
    }
};

class Solution2 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        combinationSumHelper(candidates, target, 0, path, result);
        return result;
    }
    void combinationSumHelper(vector<int>& candidates, int& target, int startIdx, vector<int>& path, vector<vector<int>>& result) {
        if(target == 0){
            result.push_back(path);
            return ;
        }
        for(int i=startIdx; i<candidates.size(); i++){
            if(target < candidates[i]) continue;
            target -= candidates[i];
            path.push_back(candidates[i]);
            combinationSumHelper(candidates, target, i, path, result);      
            target += candidates[i];        
            path.pop_back();
             
        }
    }
};