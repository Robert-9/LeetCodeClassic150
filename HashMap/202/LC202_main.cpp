#include<unordered_map>
#include<iostream>
// #include
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        vector<int> nums = getNums(n);
        unordered_map<int, int> sumMap;
        int squareSum = 0;
        for(int i=0; i<nums.size(); i++){
            squareSum += nums[i]*nums[i];
        }
        if(squareSum == 1){
            return true;
        }
        else if (sumMap[squareSum]>0)
        {
            return false;
        }
        else{
            sumMap[squareSum]++;
        }
        
        
    }
private:
    vector<int> getNums(int n){
        vector<int> result;
        while(n>0){
            result.push_back(n % 10);
            n /= 10;
        }
        
    }
};