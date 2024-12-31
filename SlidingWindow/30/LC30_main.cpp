/*
    给定一个字符串 s 和一个字符串数组 words。 words中所有字符串 长度相同。

    s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。

    例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
    返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。


    测试已通过！
    一开始没用滑窗，用的直接数 wordsNum*wordLen 范围内的单词个数，复杂度没通过
    修改后成了：右移增加，左移减少，即“滑动”的做法

    注意应该是 
        滑窗内的加 words中的减 为0则删除键   这样可通过字典是否为空来判断是不是完全相等
        一开始用的是  滑窗内的减 words中的加  这样会出现消不掉负数的情况（滑窗中可能有words中没有的 就会加不回来）
*/
#include "../head_sw.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty())
            return {};

        vector<int> result;
        unordered_map<string, int> wordMap;

        int wordsNum = words.size();
        int wordLen = words[0].size();
        int bound = s.size() - wordLen*wordsNum;
        if (bound < 0)
            return {};
        else if (bound == 0)
            bound++;
        int start = 0;
        int cnt = 0;

        for (auto word : words) {
            wordMap[word]++;
        }
        unordered_map<string, int> map;
        // 窗长固定，只需指定开始的位置start即可
        for (int i = 0; i < wordLen; i++) {
            start = i;
            // 以i为起点 创建滑窗
            map.clear();
            for (int j = 0; j < wordsNum; j++) {
                string word = s.substr(i + j * wordLen, wordLen);
                map[word]++; // 将滑窗内的单词加入map
            }
           for (string &word: words) {
               if (--map[word] == 0) {
                   map.erase(word);
               }
           }

            while (start < bound) { // 小于s的长度即可
                if (start != i) {
                    string right = s.substr(start + wordLen * (wordsNum - 1), wordLen);
                    string left = s.substr(start - wordLen, wordLen);
                    map[right]++;
                    map[left]--;
                    if (map[left] == 0) {
                        map.erase(left);
                    }
                    if (map[right] == 0) {
                        map.erase(right);
                    }
                }

                if (map.empty()) {
                    result.push_back(start);
                }
                start += wordLen;
            }
        }

        return result;
    }
};

int main(){
    Solution s;
    string str = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<string> words = {"fooo","barr","wing","ding","wing"};
    vector<int> result = s.findSubstring(str, words);
    for(auto i: result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}