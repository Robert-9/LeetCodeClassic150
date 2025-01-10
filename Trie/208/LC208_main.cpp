/*
    字典树，有时也被称为前缀树。因为它可以利用字符串的公共前缀来节省存储空间
    Trie（发音类似 "try"）是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。
    这一数据结构有相当多的应用情景，例如自动补全和拼写检查。

    节点结构：

    每个节点代表一个字符。
    从根节点到某个节点的路径表示一个字符串（或字符串的前缀）。
    通常用一个标志位（如 isEndOfWord）来标记某个节点是否是一个完整字符串的结尾。

    请你实现 Trie 类：
        Trie() 初始化前缀树对象。
        void insert(String word) 向前缀树中插入字符串 word 。
        boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
        boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
             root
             /   \
            a     b
           /       \
          p         a
         / \         \
        p   r         n
       /     \         \
       l       i        a
        \       \        \
         e       l        n
                           \
                            a
*/
#include "../head_trie.h"


struct TrieNode {
    unordered_map<char, TrieNode*> children; // 每个不同字符是一个键 每个键对应一个子节点作为值
    bool isEndofWord;
    TrieNode() : isEndofWord(false) {}
};

class Trie {
private:
    TrieNode* root; 
public:
    Trie() {  // 构造函数
        root = new TrieNode(); 
    }


    void insert(string word) {
        TrieNode* curr = root;

        for (auto ch : word) {
            if (!curr->children.count(ch)) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->isEndofWord = true;
    }


    bool search(string word) {
        TrieNode* curr = root;
        for (auto ch : word) {
            if (curr->children.count(ch)) {
                curr = curr->children[ch];
            } else
                return false;
        }
        if (curr->isEndofWord) {
            return true;
        } else
            return false;
    }


    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (auto ch : prefix) {
            if (curr->children.count(ch)) {
                curr = curr->children[ch];
            } else
                return false;
        }
        return true;
    }
};


/*
    输入
        ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
        [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
    输出
        [null, null, true, false, true, null, true]
    解释
        Trie trie = new Trie();
        trie.insert("apple");
        trie.search("apple");   // 返回 True
        trie.search("app");     // 返回 False
        trie.startsWith("app"); // 返回 True
        trie.insert("app");
        trie.search("app");     // 返回 True

    Your Trie object will be instantiated and called as such:
        Trie* obj = new Trie();
        obj->insert(word);
        bool param_2 = obj->search(word);
        bool param_3 = obj->startsWith(prefix);
*/