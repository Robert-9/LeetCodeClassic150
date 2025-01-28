/*
    给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
    单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
    同一个单元格内的字母不允许被重复使用。
*/
#include "../head_backtrack.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0] && existHelper(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
    bool existHelper(vector<vector<char>>& board, string& word, int row, int col, int curr){
        if (curr >= word.size()){
            return true;
        }
        if(board[row][col] == word[curr]) {
            int temp = board[row][col];
            board[row][col] = '#';

            int dx[4] = {1, -1, 0, 0};
            int dy[4] = {0, 0, 1, -1};
            for(int k=0; k<4; k++){
                int x = row+dx[k];
                int y = col+dy[k];
                if(x>=0 && x<board.size() && y>=0 && y<board[0].size() && board[x][y] != '#'){
                    if(!existHelper(board, word, x, y, curr+1)){
                        return false;
                    }
                } else {
                    continue;
                }
            }
            board[row][col] = temp;
        } else  
            return false;
        return true;
    }
};