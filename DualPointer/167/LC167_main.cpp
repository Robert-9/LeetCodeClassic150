/*
    给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。
    如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。
    以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。
    你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。
    你所设计的解决方案必须只使用常量级的额外空间。

    answer中的双指针法简洁很多
*/

#include <vector>

using namespace std;



class Solution {
private:
    int binarySearch(vector<int>& numbers, int value, int left, int right){
        /*
            二分查找  返回-1则是没找到
        */
        int mid = left + (right - left)/2;
        if(left<= right){
            if(value > numbers[mid]){
                return binarySearch(numbers, value, mid+1, right);
            } else if(value < numbers[mid]){
                return binarySearch(numbers, value, left, mid-1);
            } else {
                return mid;
            }
        } else{
            return -1;
        }
    }
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;

        int len = numbers.size();
        for(int i=0; i<len; i++){
            int res = binarySearch(numbers, target-numbers[i], 0, len-1);
            if(res != -1){
                if(i == res && i+1 < len && numbers[i] == numbers[i+1]){  // 对于测试输入[1,2,3,4,4,9,56,90] 8
                    result.push_back(i+1);
                    result.push_back(i+2);
                } else{
                    result.push_back(i+1);
                    result.push_back(res+1);
                }
                return result;
            }
        }
        return result;
    }
};