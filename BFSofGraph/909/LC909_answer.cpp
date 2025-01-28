#include "../../Graph/head_graph.h"

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false); // 标记是否访问过
        queue<pair<int, int>> q; // {当前格子编号, 步数}
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int currPos = curr.first;
            int steps = curr.second;
            
            if (currPos == n * n) {
                return steps;  // 到达终点
            }

            // 遍历下一步的6种可能
            for (int j = 1; j <= 6; j++) {
                int nextPos = currPos + j;
                
                if (nextPos > n * n) {  // 超出棋盘范围
                    break;
                }

                // 获取下一步的坐标
                vector<int> coor = getAdd(nextPos, n);
                int x = coor[0], y = coor[1];

                // 如果有蛇或梯子，跳到目标位置
                if (board[x][y] != -1) {
                    nextPos = board[x][y];
                }

                // 如果目标位置未被访问过，加入队列
                if (!visited[nextPos]) {
                    visited[nextPos] = true;
                    q.push({nextPos, steps + 1});
                }
            }
        }

        // 如果无法到达终点
        return -1;
    }

    // 获取格子的坐标
    vector<int> getAdd(int curr, int n) {
        int x = n - 1 - (curr - 1) / n; // 行号
        int y = (curr - 1) % n; // 列号
        if ((n - 1 - x) % 2 == 1) { // 奇数行从右往左
            y = n - 1 - y;
        }
        return {x, y};
    }
};