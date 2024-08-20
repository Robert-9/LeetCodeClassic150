/*
    如果从当前出发点无法绕行一圈，外层循环中的 i 更新为 i + cnt + 1，表示直接跳过当前检查的所有加油站，
    因为我们已经确定从 i 到 i + cnt 的这些加油站都无法作为出发点（因为它们的累加油量不足以支撑行驶）。

    这样考虑：
        如果以 i 到 i + cnt 的某个点为起点，在这一点的油量是为0的；
        而以 i 为起点，经过  i 到 i + cnt 的某个点时，由于是从前面的点来的，到这一点的油量会是大于0的；
        如果在这一点大于0都不能走完，等于0肯定也不能走完。所以可以直接跳过这中间的所有节点！
*/


#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) {
                    break;
                }
                cnt++;
            }
            if (cnt == n) {  // 等于n，说明在内层while中走完了一整圈，说明以该点为起点可以走完完整的一圈
                return i;
            } else {  // 不等于n（小于），说明提前break了，则这期间的所有节点全部跳过
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};
