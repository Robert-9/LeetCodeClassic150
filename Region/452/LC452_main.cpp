/*
    有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。

    一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。

    给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。

    可能的情况：
        [  ]   [  ]     [     ]   [  ]     [ ]
        [ ]    [    ]     [ ]       [  ]       [  ]
*/
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

// 求交集 前一个的右值和后一个的左值进行比较
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() < 2){
            return points.size();
        }
        sort(points.begin(), points.end());

        vector<vector<int>> merge;
        merge.push_back(points[0]);  // merge是取交后的区间，按左值排序，由于取交后一定没有重叠，而points也已经按左值排序，故只需和最后一个merge比较
        for(int i=1; i<points.size(); i++){
            if(points[i][0] > merge.back()[1]){  // 无重叠
                merge.push_back(points[i]);
            } 
            // else if(points[i][1] >= merge.back()[1]){
            //     merge.back() = {max(merge.back()[0], points[i][1]), merge.back()[1]};
            // }
            // else {
            //     merge.back() = {max(merge.back()[0], points[i][0]), points[i][1]};
            // }
            else {
                merge.back()[1] = min(merge.back()[1], points[i][1]);  // 只考虑右边界即可！假定总是从右边界这一个点上射箭，无需再计算左边界！
            }            
        }
        return merge.size();
    }
};