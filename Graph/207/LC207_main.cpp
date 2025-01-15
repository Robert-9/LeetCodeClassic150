/*
    你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

    在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

    例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
    请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
*/
#include "../head_graph.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;

        // 保存每个节点的入度, 初始化为全0
        vector<int> inDegree(numCourses, 0);

        // 创建度为0的节点集合
        vector<int> result;

        // 创建图，同时得到度为0的节点集合
        for(auto pre : prerequisites){
            graph[pre[0]].push_back(pre[1]);
        }
        // 1. 统计每个节点的入度
        for (const auto& pairs : graph) {
            for (int neighbor : pairs.second) {
                inDegree[neighbor]++;
            }
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
            return false;  // 图中有环，返回空结果
        }
        return true;
    }

};