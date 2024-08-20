/*
    在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

    你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

    给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。

    测试已通过，但复杂度为O(N^2)
    answer中的方法复杂度O(N)，有两个while但实际只遍历一次。


*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        
        for(int i=0; i<len; i++){
            if(gas[i] < cost[i]) continue;
            int count = 0;
            int remain = 0;
            while(remain >0 || count == 0){
                int index = (count+i)%len;
                remain += gas[(count+i)%len];
                remain -= cost[(count+i)%len];
                count++;
                if(count >= len && remain>=0){
                    return i;
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution solution;
    vector<int> gas = {4,5,3,1,4};
    vector<int> cost = {5,4,3,4,2};
    int res = solution.canCompleteCircuit(gas, cost);

    cout<< res;
}