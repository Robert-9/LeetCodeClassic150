/*
    以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
    请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
*/

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return intervals;
        } else if (intervals.size() == 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());  // 注意这个用法，使得intervals按每一维的第一个数字的大小排序，且时间和空间复杂度低于手写的排序算法
        
        int valStart = intervals[0][0], valEnd = intervals[0][1]; // 已经合并的区间范围
        vector<vector<int>> result;
        
        for (int i = 1; i < intervals.size() + 1; i++) {
            while (i < intervals.size() &&
                   intervals[i][0] <= valEnd) { // 有重叠
                valEnd = max(valEnd, intervals[i][1]);
                i++;
            }

            vector<int> temp;
            temp.push_back(valStart);
            temp.push_back(valEnd);
            result.push_back(temp);

            if (i < intervals.size()) {
                valStart = intervals[i][0];
                valEnd = intervals[i][1];
            }
        }

        return result;
    }
};