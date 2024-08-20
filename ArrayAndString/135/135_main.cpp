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
    int calCandy(vector<int>& ratings){
        int minVal = 1;
        int prev = 1;
        int cur = 1;
        int sum = 1;
        for(int i=1; i<ratings.size(); i++){
            if (ratings[i] > ratings[i - 1]) {
                cur = prev + 1;
            } else {
                cur = 1;
                // if (cur < minVal) {
                //     minVal = cur;
                // }
            }
            sum += cur;
            prev = cur;
        }

        // if(minVal < 1){
        //     sum = sum + (1-minVal) * (ratings.size());
        // }
        return sum;
    }
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        int res1 = calCandy(ratings);
        // reverse(ratings.begin(), ratings.end());
        // int res2 = calCandy(ratings);
        // return (res1 > res2) ? res2 : res1;
        return res1;
    }
};


int main(){
    Solution solution;
    vector<int> candy = {1,2,87,87,87,2,1};
    int res = solution.candy(candy);

    cout<< res;
}