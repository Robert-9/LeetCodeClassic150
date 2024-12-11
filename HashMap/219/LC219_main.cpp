/*
    给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，
    满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

    已通过测试，但效率较低:
        1.使用了 unordered_map<int, vector<int>> 来存储每个数字出现的所有索引，但这是不必要的。
          只需要存储上一个出现的索引即可，大幅减少空间复杂度和时间复杂度。
        2.在第二个循环中用 break 跳出，但即便修正逻辑，这种方式的效率依然不高。可以通过更好的算法避免双层循环。
*/
#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool result = false;
        unordered_map<int, vector<int>> numMap;
        for(int i=0; i<nums.size(); i++){
                numMap[nums[i]].push_back(i);
        }
        for(auto pair: numMap){
            for(int j=0; j<pair.second.size()-1; j++){
                if(pair.second[j]+k >= pair.second[j+1]){
                    result = true;
                    break;
                }
            }
            if(result == true){
                break;                
            }
        }

        return result;
    }
};