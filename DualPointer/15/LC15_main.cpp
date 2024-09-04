/*
    给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 
    满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。
    请你返回所有和为 0 且不重复的三元组。
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int findThirdIndex(vector<int>& nums, int start, int value){
        /*
            从已排好序的数组中，指定的起始下标开始，找相应的值。存在则返回对应下标，不存在则返回-1
        */
        if(value < nums[start]) return -1;

        int end = nums.size()-1;
        int mid = start + (end-start)/2;

        if(value < nums[mid]){
            return findThirdIndex(nums, start, mid);
        } else if(value > nums[mid]){
            return findThirdIndex(nums, mid, end);
        } else{
            return mid;
        }
    }
    void Merge(vector<int>& nums, int left, int mid, int right){      
        vector<int> leftSub(nums.begin()+left, nums.begin()+mid+1);
        vector<int> rightSub(nums.begin()+mid+1, nums.begin()+right+1);

        int i=0, j=0, k=left;
        while(i < leftSub.size() && j < rightSub.size()){
            if(leftSub[i] < rightSub[j]){
                nums[k++] = leftSub[i++];
            } else {
                nums[k++] = rightSub[j++];
            }
        }
        while(i < leftSub.size()){
            nums[k++] = leftSub[i++];
        }
        while(j < rightSub.size()){
            nums[k++] = rightSub[j++];
        }
        

    }
    void mergeSort(vector<int>& nums, int left, int right){
        if(left >= right){
            return ;
        }

        int mid = left + (right-left)/2;        

        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);

        Merge(nums, left, mid, right);
    }
    vector<int> dualPointer2Sum(vector<int>& nums, int start, int targetSum){
        int left = start;
        int right = nums.size()-1;
        vector<int> res;

        while(left < right){
            if(nums[left] + nums[right] > targetSum){
                right--;
            } else if(nums[left] + nums[right] < targetSum){
                left++;
            } else{
                res.push_back(left);
                res.push_back(right);
                return res;
            }
        }

    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        if(len < 3) return  result;

        mergeSort(nums, 0, nums.size()-1);

        // for(int i=0; i<len; i++){
        //     for(int j=i; j<len; j++){
        //         int k = j;
        //         int thirdIndex = findThirdIndex(nums, k, -nums[i]-nums[j]);
        //         if(thirdIndex != -1){
        //             vector<int> res;
        //             res.push_back(nums[i]);
        //             res.push_back(nums[j]);
        //             res.push_back(nums[thirdIndex]);
        //             result.push_back(res);
        //         }
        //     }
        // }

        for(int i=0; i<len; i++){
            dualPointer2Sum(nums, i, -nums[i]);
        }

        return result;

    }
};