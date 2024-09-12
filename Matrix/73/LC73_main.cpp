/*
    给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法


    结果是对的，但仍用了额外的空间！不算严格意义上的原地
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
private:
    void setRowColZeros(vector<vector<int>>& coords, vector<vector<int>>& matrix){
        for(auto coord:coords){
            int row = coord[0];
            int col = coord[1];
            for(int i=0; i<matrix.size(); i++){
                matrix[i][col] = 0;
            }
            for(int j=0; j<matrix[0].size(); j++){
                matrix[row][j] = 0;
            }
        }

    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> coords;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[i][j] == 0){
                    vector<int> co = {i, j};
                    coords.push_back(co);
                }
            }
        }
        setRowColZeros(coords, matrix);
    }
};