/*
    n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

    你需要按照以下要求，给这些孩子分发糖果：

    每个孩子至少分配到 1 个糖果。
    相邻两个孩子评分更高的孩子会获得更多的糖果。
    请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 

*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int calMin(vector<int>& ratings, int len){
        /*
            寻找第一个最小值
        */
        int minVal = 2 * 10000;
        int minIndex = 0;
        for(int i=0; i<len; i++){
            if(ratings[i] < minVal){
                minVal = ratings[i];
                minIndex = i;
            }
        }
        
        return minIndex;
    }
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;

        int len = ratings.size();
        int result = 1;
        int prev = 1;

        int minIndex = calMin(ratings, len);
        if(minIndex != 0){
            for(int i=minIndex-1; i>=0; i--){
                if(ratings[i] < ratings[i+1]){
                    result += prev-1;
                    prev = prev-1;
                }
                else if(ratings[i] > ratings[i+1]){
                    result += prev+1;
                    prev = prev+1;
                }
                else if(ratings[i] == ratings[i+1]){
                    if(prev != 1){
                        result += prev-1;
                    } else{
                        result += prev+1;
                    }
                }
            }
        }
        prev = 1;
        if(minIndex != len-1){
            for(int i=minIndex+1; i<len; i++){
                if(ratings[i] < ratings[i-1]){
                    result += prev-1;
                    prev = prev-1;
                }
                else if(ratings[i] > ratings[i-1]){
                    result += prev+1;
                    prev = prev+1;
                }
                else if(ratings[i] == ratings[i-1]){
                    if(prev != 1){
                        result += prev-1;
                        prev = prev-1;
                    } else{
                        result += prev+1;
                        prev = prev+1;
                    }
                }
            }
        }

        return result;
    }
};


int main(){
    Solution solution;
    vector<int> candy = {1,2,87,87,87,2,1};
    // vector<int> candy = {1,3,2,2,1};
    int res = solution.candy(candy);

    cout<< res;
}