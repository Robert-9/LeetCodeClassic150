#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) {
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);  // 已有的长度+当前位置可以到达的长度
        }
        return true;
    }
};
