#include "../head_backtrack.h"


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty() || word.empty()) return false;
        if (word.size() > board.size() * board[0].size()) return false;

        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> isVisited(rows, vector<bool>(cols, false)); // 标记是否访问过

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // 从起始位置匹配
                if (board[i][j] == word[0] && existHelper(board, word, isVisited, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool existHelper(vector<vector<char>>& board, string& word, vector<vector<bool>>& isVisited,
                     int row, int col, int curr) {
        if (curr == word.size()) return true; // 匹配完成
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||
            board[row][col] != word[curr] || isVisited[row][col]) {
            return false; // 越界、不匹配或已访问
        }

        isVisited[row][col] = true; // 标记当前单元格为已访问

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for (int k = 0; k < 4; k++) {
            int x = row + dx[k];
            int y = col + dy[k];
            if (existHelper(board, word, isVisited, x, y, curr + 1)) {
                return true;
            }
        }

        isVisited[row][col] = false; // 回溯时取消标记
        return false;
    }
};
