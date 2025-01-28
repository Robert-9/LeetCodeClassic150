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