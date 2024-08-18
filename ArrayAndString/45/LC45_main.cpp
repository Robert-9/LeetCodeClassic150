/*
    描述
        给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。
        每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:
        题目保证可以到达 nums[n-1]

        55只判断是否能跳到，本题要求返回最小跳跃次数
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty()) return 0;

        int n = nums.size();
        vector<int> dp(n);  // 表示到下标为n的点需要的最小步数
        int maxReach = nums[0];
        int start = 0;

        dp[0] = 0;
        for(int i=1; i<n; i++){
            if(i <= maxReach){
                dp[i] = dp[i-1];
            } else{
                // 更新maxReach
                for(int j=start; j<i; j++){
                    if(nums[j]+j >= maxReach){
                        maxReach = nums[j]+j;
                        start = j;
                    }
                }
                dp[i] = dp[i-1] + 1;
            }
            if(maxReach == n-1){
                return dp[i];
            }
        }
    }
};