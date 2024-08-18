#include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int result = 1;  // 结果数组的长度
        int count = 1;   // 当前元素的计数

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                count = 1;  // 新元素出现时，计数重置为1
            }

            // 如果元素出现次数不超过2次，保存该元素
            if (count <= 2) {
                nums[result++] = nums[i];
            }
        }

        return result;
    }
};
