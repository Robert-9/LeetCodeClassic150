/*
    给你一个 n * n 矩阵 grid ，矩阵由若干 0 和 1 组成。请你用四叉树表示该矩阵 grid 
    你需要返回能表示矩阵 grid 的 四叉树 的根结点。

    四叉树数据结构中，每个内部节点有四个子节点，每个节点都有两个属性：
        isLeaf: 当这个节点是一个叶子结点时为 True，如果它有 4 个子节点则为 False 。
        val：储存叶子结点所代表的区域的值。1 对应 True，0 对应 False。
        当 isLeaf 为 False 时，你可以把 True 或者 False 赋值给节点，两种值都会被判题机制 接受 。


    我们可以按以下步骤为二维区域构建四叉树：
        如果当前网格的值相同（即，全为 0 或者全为 1），将 isLeaf 设为 True ，将 val 设为网格相应的值，并将四个子节点都设为 Null 然后停止。
        如果当前网格的值不同，将 isLeaf 设为 False， 将 val 设为任意值，然后如下图所示，将当前网格划分为四个子网格。
        使用适当的子网格递归每个子节点。

    n == grid.length == grid[i].length
    n == 2x 其中 0 <= x <= 6
*/

#include "../head_d&c.h"

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        Node* result;
        if(grid.empty()) return result;

        int n = grid.size();
        result = constructHelper(grid, 0, 0, n);

        return result; 
    }
    Node* constructHelper(vector<vector<int>>& grid, int xStart, int yStart, int n){  // xStart,yStart  为左上顶点索引

        Node* curr = new Node();
        if(n == 1 || isLeafFunc(grid, xStart, yStart, n)){
            curr->isLeaf = true;
            curr->val = grid[xStart][yStart];
            curr->topLeft = nullptr;
            curr->topRight = nullptr;
            curr->bottomLeft = nullptr;
            curr->bottomRight = nullptr;
        }
        else{
            curr->isLeaf = false;
            curr->val = grid[xStart][yStart];
            curr->topLeft = constructHelper(grid, xStart, yStart, n/2);
            curr->topRight = constructHelper(grid, xStart, yStart+n/2, n/2);
            curr->bottomLeft = constructHelper(grid, xStart+n/2, yStart, n/2);
            curr->bottomRight = constructHelper(grid, xStart+n/2, yStart+n/2, n/2);
        }
        return curr;
    }

    bool isLeafFunc(vector<vector<int>>& grid, int xStart, int yStart, int n){
        bool temp = grid[xStart][yStart];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(temp != grid[xStart+i][yStart+j]){
                    return false;
                }
            }
        }
        return true;
    }
};