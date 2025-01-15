/*
    给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' 组成，捕获 所有 被围绕的区域：
        连接：一个单元格与水平或垂直方向上相邻的单元格连接。
        区域：连接所有 'O' 的单元格来形成一个区域。
        围绕：如果您可以用 'X' 单元格 连接这个区域，并且区域中没有任何单元格位于 board 边缘，则该区域被 'X' 单元格围绕。
        通过 原地 将输入矩阵中的所有 'O' 替换为 'X' 来 捕获被围绕的区域。你不需要返回任何值。


        测试已通过，改了很久。
        思路是  先用solveHelper递归判断当前区域是不是被“围绕”， 同时给相连的区域全部打上 已访问 的标记， 
                如果是被围绕的则用catchFun修改，不是则不修改。
                solveHelper的返回值为 是不是被围绕
        一开始用的result = result && solveHelper递归    但这样会触发与运算的短路机制，不能将整个连通的区域全部遍历并打上已访问的标记 导致后面赋值出错
        后面改成了必须朝四个方向全部遍历，并对四个方向的结果做与运算，即保证四个方向的计算都完成，
        同时将result改成了全局变量（其实不是全局变量应该也可以）


        GPT给的答案思路巧妙很多！！！
        详见answer
*/
#include "../head_graph.h"

class Solution {
public:
    bool result = true;
    void solve(vector<vector<char>>& board) {
        if (board.empty())
            return;

        vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O' && !isVisited[i][j]) {  // 只有 'O' 会有isVisited标记
                    result = true;
                    if (solveHelper(board, i, j, isVisited)) {
                        catchFun(board, i, j);
                    }
                }
            }
        }
    }
    bool solveHelper(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& isVisited) {
        // 如果超出边界，则说明'O'在边界上，即当前区域没有被围绕，返回false
        if (x < 0 || x > board.size() - 1 || y < 0 || y > board[0].size() - 1)  {
            return false;
        }

        if (board[x][y] == 'X' || isVisited[x][y]) {  // 若递归输入为 'X' 或 已经访问过的 'O' 则返回
            return true;
        }

        isVisited[x][y] = true;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        bool res[4] = {true, true, true, true};

        for (int i = 0; i < 4; i++) {
            res[i] = solveHelper(board, x + dx[i], y + dy[i], isVisited);  // 避免短路特性
        }
        result = result && res[0] && res[1] && res[2] && res[3];
        return result;
    }
    void catchFun(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'O') {
            return;
        }

        board[x][y] = 'X';
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++) {
            catchFun(board, x + dx[i], y + dy[i]);
        }
    }
};


int main() {
    vector<vector<char>> board = {{'O','O','O','O','X','X'},
                                  {'O','O','O','O','O','O'},
                                  {'O','X','O','X','O','O'},
                                  {'O','X','O','O','X','O'},
                                  {'O','X','O','X','O','O'},
                                  {'O','X','O','O','O','O'}};

    // vector<vector<char>> board = {{'O','X','O'},
    //                               {'X','O','X'},
    //                               {'O','X','O'}};

    Solution solve;
    solve.solve(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}