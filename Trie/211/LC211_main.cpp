/*
    请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。

    实现词典类 WordDictionary ：

    WordDictionary() 
        初始化词典对象
    void addWord(word) 
        将 word 添加到数据结构中，之后可以对它进行匹配
    bool search(word) 
        如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些 '.' ，每个 . 都可以表示任何一个字母。
 
*/
#include "../head_trie.h"


struct wdNode {
    unordered_map<char, wdNode*> children;
    bool isEndofWords;

    wdNode() : isEndofWords(false) {};
    wdNode(bool isEnd) : isEndofWords(isEnd) {};
    wdNode(bool isEnd, unordered_map<char, wdNode*> next)
        : isEndofWords(isEnd), children(next) {};
};

class WordDictionary {
public:
    wdNode* root;
    WordDictionary() { root = new wdNode(); }

    void addWord(string word) {
        wdNode* curr = root;
        for (auto ch : word) {
            if (!curr->children.count(ch)) {
                curr->children[ch] = new wdNode();
            }
            curr = curr->children[ch];
        }
        curr->isEndofWords = true;
    }

    bool search(string word) { // 可能包含 .
        return searchHelper(root, word);
    }

    bool searchHelper(wdNode* root, string& word) {
        if (root->children.empty() && !word.empty())
            return false;
        else if (!root->children.empty() && word.empty()) {
            if (root->isEndofWords) {
                return true;
            } 
            else
                return false;
        } 
        else if (root->children.empty() && word.empty())
            return true;
        wdNode* curr = root;

        for (int i = 0; i < word.size(); i++) {
            if (curr->children.count(word[i])) {
                curr = curr->children[word[i]];
            } 
            else if (word[i] != '.' || curr->children.empty()) {
                return false;
            } 
            else { // 为'.'
                string subWord = word.substr(i + 1, word.size());
                // if(subWord.empty()) break;
                bool subResTotal = false;
                for (auto pair : curr->children) {
                    bool res = searchHelper(pair.second, subWord);
                    if (res)
                        return true;
                }
                return false;
            }
        }
        if (curr->isEndofWords) {
            return true;
        } else
            return false;
    }
};