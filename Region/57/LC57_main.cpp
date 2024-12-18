/*
    给你一个 无重叠的 ，按照区间起始端点排序的区间列表 intervals，其中 intervals[i] = [starti, endi] 表示第 i 个区间的开始和结束，
    并且 intervals 按照 starti 升序排列。同样给定一个区间 newInterval = [start, end] 表示另一个区间的开始和结束。
    在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti 升序排列，且区间之间不重叠（如果有必要的话，可以合并区间）。
    返回插入之后的 intervals。

    注意 你不需要原地修改 intervals。你可以创建一个新数组然后返回它。

    测试已通过，但补了很多if用于特殊情况判断：主要是考虑到三种区间情况，小于需要插入的区间，有重合的区间，大于的区间
    前面空的判断不需要也能过。
*/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // if(intervals.empty() && newInterval.empty()){
        //     return intervals;
        // } else if(intervals.empty()){
        //     intervals.push_back(newInterval);
        //     return intervals;
        // } else if(newInterval.empty()){
        //     return intervals;
        // }
        vector<vector<int>> result;
        bool isInsert = false;
        int newLeft = newInterval[0], newRight = newInterval[1];
        for(int i=0; i < intervals.size(); i++){
            if(newLeft <= intervals[i][1] && !isInsert){ // 进入重叠区间
                int mergeLeft = min(newLeft, intervals[i][0]);
                int mergeRight = newRight;
                while(i < intervals.size() && mergeRight > intervals[i][1]){
                    i++;
                }
                if(i != intervals.size()){
                    mergeRight = mergeRight < intervals[i][0] ? mergeRight : intervals[i][1];
                    if(mergeRight != intervals[i][1]){
                        i--;
                    }
                }
                result.push_back({mergeLeft, mergeRight});
                isInsert = true;
            } else{ // 不在重叠区间
                result.push_back(intervals[i]);
            }
        }
        if(!isInsert){
            result.push_back(newInterval);
        }
        return result;
    }
};