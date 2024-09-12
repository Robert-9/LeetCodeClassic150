
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
private:
    int numOfLiveCells(vector<vector<int>>& board, int row, int col) {
        int result = 0;
        int m = board.size();
        int n = board[0].size();

        // 定义方向数组，分别对应 8 个方向
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, 
                                             {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        // 遍历 8 个方向
        for (auto dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                if (board[newRow][newCol] == 1 || board[newRow][newCol] == -1) {
                    result++;
                }
            }
        }

        return result;
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();        

        // 第一遍遍历：标记状态
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int nums = numOfLiveCells(board, i, j);
                if (board[i][j] == 1 && (nums < 2 || nums > 3)) {
                    board[i][j] = -1; // 从活细胞变为死细胞
                } else if (board[i][j] == 0 && nums == 3) {
                    board[i][j] = 2;  // 从死细胞变为活细胞
                }
            }
        }

        // 第二遍遍历：更新状态
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -1) {
                    board[i][j] = 0; // 变成死细胞
                } else if (board[i][j] == 2) {
                    board[i][j] = 1; // 变成活细胞
                }
            }
        }
    }
};
