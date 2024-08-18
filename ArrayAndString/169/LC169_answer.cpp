/*
    Boyer-Moore 投票算法
        是一种用于在数组中寻找多数元素（即出现次数超过一半的元素）的一种高效算法。该算法由 Robert S. Boyer 和 J Strother Moore 在 1981 年提出，
    其主要优点在于：
        时间复杂度为 O(n)，因为它只需一次遍历数组。
        空间复杂度为 O(1)，因为它只需常量级别的额外空间。

    算法原理
        Boyer-Moore 投票算法的基本思想是通过计数和对消机制，找到可能的候选元素，然后验证该候选元素是否为多数元素。
*/

#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for(int num : nums) {
            if(count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};
