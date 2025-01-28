/*
    给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
    你可以按 任何顺序 返回答案。
*/
#include "../head_backtrack.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        int curr = 1;
        vector<int> com;
        combineHelper(n, k, curr, com, result);
        return result;

    }
    void combineHelper(int& n, int& k, int curr, vector<int>& com, vector<vector<int>>& result){
        if(com.size() == k) {
            result.push_back(com);
            return;
        }

        for(int i=curr; i<n; i++) {
            com.push_back(i);
            combineHelper(n, k, curr+1, com, result);
            com.pop_back();
        }
    }
};