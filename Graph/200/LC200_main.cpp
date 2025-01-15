/*
    给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
    岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
    此外，你可以假设该网格的四条边均被水包围。

    测试已通过
*/

#include "../head_graph.h"

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        vector<vector<bool>> isVisited(grid.size(), vector<bool>(grid[0].size(), false));

        int result = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(!isVisited[i][j] && grid[i][j] == '1'){
                    result++;
                    numIslandsHelper(grid, i, j, isVisited);
                }
            }
        }
        return result;

    }
    void numIslandsHelper(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& isVisited){
        isVisited[x][y] = true;
        if(grid[x][y] == '1'){
            if(x+1 < grid.size() && !isVisited[x+1][y]){
                numIslandsHelper(grid, x+1, y, isVisited);
            }
            if(x-1 >= 0 && !isVisited[x-1][y]){
                numIslandsHelper(grid, x-1, y, isVisited);
            }
            if(y+1 < grid[0].size() && !isVisited[x][y+1]){
                numIslandsHelper(grid, x, y+1, isVisited);
            }
            if(y-1 >= 0 && !isVisited[x][y-1]){
                numIslandsHelper(grid, x, y-1, isVisited);
            }
        }
    }
};