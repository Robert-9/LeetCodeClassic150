/*
    给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点。求最多有多少个点在同一条直线上。
*/
#include "../head_math.h"

// 计算最大公约数 (GCD) 欧几里得算法（辗转相除法）
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 2) return n;
        
        int max_count = 1;  // 至少有一个点

        for (int i = 0; i < n; i++) {
            unordered_map<string, int> slope_count;
            int same_point = 0, local_max = 1; 

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    // 处理重复点
                    same_point++;
                    continue;
                }

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                if (dx < 0) {  // 保持 dx 为正，保证唯一性
                    dx = -dx;
                    dy = -dy;
                }

                string slope = to_string(dx) + "/" + to_string(dy);
                slope_count[slope]++;
                local_max = max(local_max, slope_count[slope] + 1);  //  为了包含当前起点 points[i] 本身
            }
            
            max_count = max(max_count, local_max + same_point);  // 为了包含所有与当前起点 points[i] 位置完全相同的点
        }
        
        return max_count;
    }
};
