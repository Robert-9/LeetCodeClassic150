/*
    给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
    另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。
    返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替代这个答案。
    注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
    注意：未在等式列表中出现的变量是未定义的，因此无法确定它们的答案。
*/
#include "../head_graph.h"


class Solution {  
public:  
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, vector<vector<string>>& queries) {  
        vector<double> result;  
        unordered_map<string, unordered_map<string, double>> graph;  
    
        // 构建图  
        int idx = 0;  
        for(auto varPair : equations){  
            graph[varPair[0]][varPair[1]] = values[idx];  
            graph[varPair[1]][varPair[0]] = 1 / values[idx];  
            idx++;  
        }  
        // 逐个判断queries(问题)中的变量对的结果  首先保证两个变量都在图中，再递归计算结果
        for(auto query : queries){  
            if(!graph.count(query[0]) || !graph.count(query[1])){ // 未在等式列表里出现的变量 query中的两个都要判断  
                result.push_back(-1);  
            }  
            else {  
                unordered_set<string> visited;    
                double res = dfs(graph, query[0],  query[1], 1, visited);  
                result.push_back(res);  
            }  
        }  

        return result;  
    }  
    
    double dfs(unordered_map<string, unordered_map<string, double>>& graph, 
                            string curr, string target, double mul, unordered_set<string>& visited) {  
        if (visited.find(curr) != visited.end()) return -1;  
        
        visited.insert(curr);              // 标记为已访问(实际可看作是保存路径)
        if (curr == target) return mul;   // 到了指定位置
    
        for(auto pair  : graph[curr]){  
            double res = dfs(graph, pair.first, target,mul*pair.second, visited);  
            if(res >= 0) {  
                return res;  
            }  
        }  
        visited.erase(curr); // 从当前递归回退时需要取消 已访问 的标记 避免其他同样连接到当前节点的节点无法访问
        return -1;  
    }  
}; 
