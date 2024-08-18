/*
    给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
    你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
    返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/

#include <vector>
using namespace std;

class Solution {
private:
    int findMax(vector<int>& prices, int start){
        int res = start;
        for(int j=start; j<prices.size(); j++){
            if(prices[j] >= prices[res]){  // 用大于等于，尽可能将j往后找，既返回一个尽可能大的maxIndex，以减少复杂度
                res = j;
            }
        }
        return res;
    }
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;

        int result = 0;
        int maxIndex = 0;

        for(int i=0; i<prices.size(); i++){
            if(i==maxIndex){
                maxIndex = findMax(prices, i);
            }
            if(result < prices[maxIndex]-prices[i]){
                result = prices[maxIndex]-prices[i];
            }
        }
        return result;

    }
};