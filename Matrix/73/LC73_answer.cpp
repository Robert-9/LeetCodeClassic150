#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {  
public:  
    void setZeroes(vector<vector<int>>& matrix) {  
        int m = matrix.size();  
        int n = matrix[0].size();  
        int flag_col0 = false;  
        for (int i = 0; i < m; i++) {  
            if (!matrix[i][0]) {  // 查找第一列是否有0  
                flag_col0 = true;  
            }  
            for (int j = 1; j < n; j++) {  
                if (!matrix[i][j]) {  // i固定，增加j 实际是判断当前行是否有0
                    matrix[i][0] = matrix[0][j] = 0;  // 由于是先if判断过了当前行的第一个元素是不是0并更新了标志位状态，故此时改变第一个元素不会影响
                }  
            }  
        }  
        for (int i = m - 1; i >= 0; i--) {  
            for (int j = 1; j < n; j++) {  
                if (!matrix[i][0] || !matrix[0][j]) {  
                    matrix[i][j] = 0;  
                }  
            }  
            if (flag_col0) {  
                matrix[i][0] = 0;  
            }  
        }  
    }  
};  