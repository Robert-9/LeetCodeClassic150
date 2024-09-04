/*
    给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

    测试未通过
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int result = 0;
        int len = height.size();
        vector<int> temp;
        
        for(int i=0; i<len; i++){
            if(height[i] == ){
                temp.push_back();
            }
        }

        return result;
    }
};