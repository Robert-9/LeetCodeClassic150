/*
    n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。
    给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
*/
#include "../head_backtrack.h"

class Solution {
public:
    int totalNQueens(int n) {
        unordered_set<int> colSet;
        unordered_set<int> diagSet1;
        unordered_set<int> diagSet2;
        int result;
        totalNQueensHelper(n, 0, colSet, diagSet1, diagSet2, result);
        return result;
    }
    int totalNQueensHelper(int n, int currRow, unordered_set<int> colSet, 
                            unordered_set<int> diagSet1, unordered_set<int> diagSet2, int& result) {
        if(currRow > n) {
            result++;
        }
        for(int i=0; i<n; i++) {
            if(!colSet.count(i) && !diagSet1.count(currRow+n) 
                && !diagSet2.count(currRow-n)){  // 不在各个集合中
                colSet.insert(i);
                diagSet1.insert(i);
                diagSet2.insert(i);
                totalNQueensHelper(n, currRow+1, colSet, diagSet1, diagSet2, result);
                colSet.erase(i);
                diagSet1.erase(i);
                diagSet2.erase(i);
            }
        }
    }
};