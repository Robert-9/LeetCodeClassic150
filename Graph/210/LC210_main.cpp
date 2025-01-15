/*
    现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。

    例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
    返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。

*/

#include "../head_graph.h"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        
        // 1. 创建图，同时统计节点的入度
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(numCourses, 0);  // 保存每个节点的入度, 初始化为全0
        for (auto pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);  
            inDegree[pre[0]]++;  
        }
        // 2. 初始化队列，将所有入度为 0 的节点加入队列
        queue<int> zeroInDegreeNodes;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                zeroInDegreeNodes.push(i);
            }
        }
        // 3. BFS 遍历
        while (!zeroInDegreeNodes.empty()) {
            int node = zeroInDegreeNodes.front();
            zeroInDegreeNodes.pop();
            result.push_back(node);  // 将当前节点加入结果

            // 遍历邻居节点，减少其入度
            for (auto neighbor : graph[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    zeroInDegreeNodes.push(neighbor);
                }
            }
        }
        // 4. 检查是否有环
        if (result.size() != numCourses) {
            return {};  // 图中有环，返回空结果
        }
        
        return result;
    }
};