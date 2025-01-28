/*
    基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。
    假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。

    例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
    另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。（变化后的基因必须位于基因库 bank 中）
    给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。
    注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。


*/

#include "../../Graph/head_graph.h"


class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int result = 0;
        if(endGene == startGene) return result;

        // 创建队列
        queue<pair<int, string>> q;
        q.push({0, startGene});
        // 使用哈希集合记录已经访问过的基因序列
        unordered_set<string> visited;
        visited.insert(startGene);

        while(!q.empty()){
            auto pair = q.front();
            int steps = pair.first;
            string curr = pair.second;

            if(curr == endGene){
                return steps;
            }

            q.pop();
            for(int i=0; i<bank.size(); i++) {
                if(visited.find(bank[i])==visited.end() && isChangeOneCh(curr, bank[i])){
                    q.push({steps+1, bank[i]});
                    visited.insert(bank[i]);
                }
            }
        }
        return -1;
    }

    bool isChangeOneCh(string curr, string target){
        int num = 0;
        for(int i=0; i<curr.size(); i++){
            if(curr[i] != target[i] && ++num >= 2){
                return false;
            }
        }
        return num==1;
    }
};