/*
    请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
        数字 1-9 在每一行只能出现一次。
        数字 1-9 在每一列只能出现一次。
        数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
*/


#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 使用布尔数组来标记数字是否已经出现
        bool row[9][9] = {false};    // 每一行中的数字是否出现
        bool col[9][9] = {false};    // 每一列中的数字是否出现
        bool square[3][3][9] = {false};  // 每一个 3x3 宫中的数字是否出现
        
        // 遍历每个格子
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';  // 将字符转化为索引（0-8）

                    // 检查当前数字在行、列、以及 3x3 宫是否已经出现
                    if (row[i][num] || col[j][num] || square[i/3][j/3][num]) {
                        return false;  // 如果已经出现，返回 false
                    }
                    
                    // 标记当前数字在相应的行、列和 3x3 宫中出现
                    row[i][num] = true;
                    col[j][num] = true;
                    square[i/3][j/3][num] = true;
                }
            }
        }
        
        return true;  // 如果没有冲突，返回 true
    }
};
