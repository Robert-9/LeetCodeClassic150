/*
    给你一个满足下述两条属性的 m x n 整数矩阵：

    每行中的整数从左到右按非严格递增顺序排列。
    每行的第一个整数大于前一行的最后一个整数。
    给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
*/
#include "../head_bs.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); 
        int n = matrix[0].size();
        return searchMatrixHelper(matrix, target, m, n, 0, m*n-1);
    }
    bool searchMatrixHelper(vector<vector<int>>& matrix, int target, int m, int n, int start, int end){
        if(start > end) return false;
        int mid = (start + end) / 2;
        int x = mid / n;
        int y = mid % n;
        if(matrix[x][y] == target) {
            return true;
        }
        if(matrix[x][y] > target) {
            end = mid-1;
        } else {
            start = mid+1;
        }
        return searchMatrixHelper(matrix, target, m, n, start, end);
    }
};