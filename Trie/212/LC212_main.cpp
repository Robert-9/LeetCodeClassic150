#include "../head_trie.h"


struct TrieNode {
    unordered_map<char, TrieNode*>
        children; // 每个不同字符是一个键 每个键对应一个子节点作为值
    bool isEndofWord;
    TrieNode() : isEndofWord(false) {}
};

class Trie {
private:
public:
    TrieNode* root;
    Trie() { // 构造函数
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
};

class Solution {
public:
    vector<string> result;
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        if (words.empty())
            return result;

        Trie wordDict;
        for (auto word : words) {
            wordDict.insert(word); // 将words中的所有单词加入字典树
        }

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                string path;
                if (wordDict.root->children.count(board[i][j])) {
                    dfs(board, m, n, i, j, wordDict.root, path);
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<char>>& board, int& m, int& n, int x, int y,
             TrieNode* root, string path) {
        if (root == nullptr)
            return;

        if (root->children.count(board[x][y])) {
            char temp = board[x][y];
            board[x][y] = '#'; // 置为已查找过
            path += temp;

            if (root->children[temp]->isEndofWord) {
                result.push_back(path);
                root->children[temp]->isEndofWord = false;
            }

            if (x + 1 < m && board[x + 1][y] != '#')
                dfs(board, m, n, x + 1, y, root->children[temp], path);
            if (x - 1 >= 0 && board[x - 1][y] != '#')
                dfs(board, m, n, x - 1, y, root->children[temp], path);
            if (y + 1 < n && board[x][y + 1] != '#')
                dfs(board, m, n, x, y + 1, root->children[temp], path);
            if (y - 1 >= 0 && board[x][y - 1] != '#')
                dfs(board, m, n, x, y - 1, root->children[temp], path);
            board[x][y] = temp;
        }
    }
};