#include <vector>

using namespace std;

class Solution {  
public:  
    vector<int> twoSum(vector<int>& numbers, int target) {  
        int left = 0;  
        int right = numbers.size() - 1;  
  
        while (left < right) {  
            int sum = numbers[left] + numbers[right];  
            if (sum == target) {  
                // 题目要求返回 1-indexed，所以要加1  
                return {left + 1, right + 1};  
            } else if (sum < target) {  
                left++;  
            } else {  
                right--;  
            }  
        }  
  
        // 按照题目要求，假设总有解，所以这里不需要处理无解情况  
        return {};  
    }  
};  