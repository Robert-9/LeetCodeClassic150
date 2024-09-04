#include <vector>
#include <algorithm>
using namespace std;

class Solution {  
public:  
    vector<vector<int>> threeSum(vector<int>& nums) {  
        vector<vector<int>> result;  
        int len = nums.size();  
        if (len < 3) return result;  
  
        // 使用 STL 提供的排序  
        sort(nums.begin(), nums.end());  
  
        for (int i = 0; i < len - 2; i++) {  
            // 跳过重复的元素  
            if (i > 0 && nums[i] == nums[i - 1]) continue;  
  
            int left = i + 1;  
            int right = len - 1;  
  
            while (left < right) {  
                int sum = nums[i] + nums[left] + nums[right];  
                if (sum == 0) {  
                    result.push_back({nums[i], nums[left], nums[right]});  
                      
                    // 跳过相同的 left 和 right  
                    while (left < right && nums[left] == nums[left + 1]) left++;  
                    while (left < right && nums[right] == nums[right - 1]) right--;  
  
                    left++;  
                    right--;  
                } else if (sum < 0) {  
                    left++;  // sum 小于 0，左指针右移增大 sum  
                } else {  
                    right--; // sum 大于 0，右指针左移减小 sum  
                }  
            }  
        }  
  
        return result;  
    }  
};  