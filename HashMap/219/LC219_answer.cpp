#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> numMap; // 存储数字及其最近一次出现的索引
        for (int i = 0; i < nums.size(); i++) {
            // 如果数字存在于 map 中，且索引差值小于等于 k，则返回 true
            if (numMap.count(nums[i]) && i - numMap[nums[i]] <= k) {
                return true;
            }
            // 更新该数字最近一次出现的索引
            numMap[nums[i]] = i;
        }
        return false; // 遍历完后仍未找到符合条件的情况
    }
};