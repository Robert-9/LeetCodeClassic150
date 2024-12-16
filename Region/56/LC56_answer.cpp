#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {  
public:  
    vector<vector<int>> merge(vector<vector<int>>& intervals) {  
        if (intervals.size() == 0) {  
            return {};  
        }  

        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());  
          
        for (int i = 0; i < intervals.size(); ++i) {  
            int start = intervals[i][0], end = intervals[i][1];  // 当前遍历到的区间的左右值

            if (!result.size() || result.back()[1] < start) {  // result为空 或者 result的最后一个区间小于当前遍历到的区间的左值（即无重叠）
                result.push_back({start, end});  
            }  
            else {  
                result.back()[1] = max(result.back()[1], end);  // 有重叠，修改result的最后一个区间的右值，左值不用动（因为前面已经按左值排序过）
            }  
        }  
        return result;  
    }  
};  