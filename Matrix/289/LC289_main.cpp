/*
    给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态： 1 即为 活细胞 （live），或 0 即为 死细胞 （dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
        1.如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
        2.如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
        3.如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
        4.如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
    下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你 m x n 网格面板 board 的当前状态，返回下一个状态。

    补充两种状态辅助作答：-1是本来为1，变为0；2是本来为0，变为1.

*/
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution{
private:
    int numOfLiveCells(vector<vector<int>>& board, int row, int col){
        /*
            判断 board中  (row,col) 位置周围的活细胞个数
        */
        int result = 0;
        int m = board.size();
        int n = board[0].size();


        if(row-1 >= 0){
            if(board[row-1][col] == 1 || board[row-1][col] == -1){
                result++;
            }
        }
        if(col-1 >= 0){
            if(board[row][col-1] == 1 || board[row][col-1] == -1){
                result++;
            }
        }        
        if(row+1 < m){
            if(board[row+1][col] == 1 || board[row+1][col] == -1){
                result++;
            }
        } 
        if(col+1 < n){
            if(board[row][col+1] == 1 || board[row][col+1] == -1){
                result++;
            }
        }
        if(row-1 >= 0 && col-1 >= 0){
            if(board[row-1][col-1] == 1 || board[row-1][col-1] == -1){
                result++;
            }
        }                 
        if(row-1 >= 0 && col+1 < n){
            if(board[row-1][col+1] == 1 || board[row-1][col+1] == -1){
                result++;
            }
        }      
        if(row+1 < m && col-1 >= 0){
            if(board[row+1][col-1] == 1 || board[row+1][col-1] == -1){
                result++;
            }
        }      
        if(row+1 < m && col+1 < n){
            if(board[row+1][col+1] == 1 || board[row+1][col+1] == -1){
                result++;
            }
        }      

        return result;
    
    }
public:
    void gameOfLife(vector<vector<int>>& board){
        int m = board.size();
        int n = board[0].size();        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int nums = numOfLiveCells(board, i, j);
                if(board[i][j] == 1 && (nums<2 || nums>3)){
                    board[i][j] = -1;
                } else if(board[i][j] == 0 && nums == 3){
                    board[i][j] = 2;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == -1){
                    board[i][j] = 0;
                } else if(board[i][j] == 2){
                    board[i][j] = 1;
                }
            }
        }
    }
};