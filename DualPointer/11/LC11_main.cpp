/*
    给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

    找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

    返回容器可以储存的最大水量。
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        if(len < 2) return 0;

        int left = 0, right = len-1;
        int maxVol = 0;

        while(left < right){
            int curVol = min(height[left], height[right]) * (right -left);

            maxVol = max(maxVol, curVol);

            // 对于left和right的移动策略是关键！！
            if(height[left] < height[right]) {  // 如果全部遍历的复杂度会很高
                left++; 
            } else {
                right--;
            }
        }
        return maxVol;
    }
};


int main(){
    Solution solution;
    vector<int> height = {2,3,4,5,18,17,6};
    solution.maxArea(height);
}