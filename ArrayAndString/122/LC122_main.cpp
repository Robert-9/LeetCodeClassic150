/*
    在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
    返回 你能获得的 最大 利润 。
*/

#include <vector>
using namespace std;

class Solution {
private:
    int profit(vector<int>& prices) {
        if(prices.empty()) return 0;

        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < minPrice) {
                minPrice = prices[i];
            } else if(prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }

        return maxProfit;
    }
public:
    int maxProfit(vector<int>& prices) {

    }
};