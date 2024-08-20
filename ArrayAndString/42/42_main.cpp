/*
    给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

    测试未通过
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int calVolumn(vector<int>& height, int left, int right){
        int res = 0;
        int bound = (height[left] > height[right])?height[right]:height[left];
        for(int j=left; j<=right; j++){
            res += (bound - height[j]);
        }
        return res;
    }
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;

        int left =0, right = 0;
        int result = 0;

        int i=0;
        while(i<height.size()){
            if(height[i] != 0){
                if(i != 0 && height[i]>=height[i-1]){
                    left = i;
                } else if(i == 0){
                    left = 0;
                } else if(height[i]<height[i-1]){
                    left = i-1;
                }
                i++;
            } else{
                i++;
                continue;
            }

            while(i<height.size() && height[i] <= height[left]){
                if(height[i] == height[left] && height[i]<=height[i+1]){
                    while(i<height.size()-1 && height[i]<=height[i+1]){
                        i++;
                    }
                    break;
                }
                i++;
            }
            right = i;
            result += calVolumn(height, left, right);
        }
        return result;
    }
};