/*
    描述：
        给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
        你可以假设数组是非空的，并且给定的数组总是存在多数元素。
        
    main中用的是空间复杂度O(n)的方法，answer用的是O(1)的方法
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;

        int threshold = nums.size()/2;
        for(int i=0; i<nums.size(); i++){
            hash[nums[i]]++;
            if(hash[nums[i]] >= threshold){
                return nums[i];
            }
        }

        return -1;
    }
};