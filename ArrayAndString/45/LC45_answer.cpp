#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int len = nums.size();
        int maxReach = 0, curReach = 0;
        
        for(int i = 0; i < len - 1; i++){
            maxReach = max(maxReach, i + nums[i]);
            
            if(i == curReach) {
                count++;
                curReach = maxReach;
            }
        }
        return count;
    }
};