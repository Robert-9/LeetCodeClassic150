/*
    给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

    借鉴了答案
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;

        int top=0;
        int left=0;
        int bottom = m-1;
        int right = n-1;
        while(top <= bottom && left <= right){
            for(int j = left; j<=right; j++){
                result.push_back(matrix[top][j]);  // 上面一行
            }
            top++;

            for(int j = top; j<=bottom; j++){  // 注意此处先做了top++  不会打印重复  后面情况类似
                result.push_back(matrix[j][right]);  // 右边一列
            }
            right--;

            if(bottom > top){
                for(int j = right; j>=left; j--){
                    result.push_back(matrix[bottom][j]);  // 下面一行
                }
                bottom--;
            }

            if(right > left){
                for(int j = bottom; j>=top; j--){
                        result.push_back(matrix[j][left]);  // 左边一列
                }      
                left++;  
            }
          
        }

        return result;
    }
};