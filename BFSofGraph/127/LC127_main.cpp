/*
    字典 wordList 中从单词 beginWord 到 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：
    每一对相邻的单词只差一个字母。
    对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
    sk == endWord
    给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。
    如果不存在这样的转换序列，返回 0 。
*/
#include "../../Graph/head_graph.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int result = 0;
        if(beginWord == endWord) return result;

        // 创建队列
        queue<pair<int, string>> q;
        q.push({0, beginWord});
        // 使用哈希集合记录已经访问过的单词
        unordered_set<string> visited;
        visited.insert(beginWord);

        while(!q.empty()){
            auto pair = q.front();
            int steps = pair.first;
            string curr = pair.second;

            if(curr == endWord){
                return steps;
            }

            q.pop();
            for(int i=0; i<wordList.size(); i++) {
                if(visited.find(wordList[i])==visited.end() && isChangeOneCh(curr, wordList[i])){
                    q.push({steps+1, wordList[i]});
                    visited.insert(wordList[i]);
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