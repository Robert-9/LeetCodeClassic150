#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int index = 0;
        
        while (index < words.size()) {
            int totalChars = words[index].size();
            int last = index + 1;
            
            // Find out how many words fit into the line
            while (last < words.size()) {
                if (totalChars + 1 + words[last].size() > maxWidth) break;
                totalChars += 1 + words[last].size();
                last++;
            }
            
            string row;
            int wordCount = last - index;
            // 到了最后一行 或 只有一个单词时, 左对齐
            if (last == words.size() || wordCount == 1) {
                for (int i = index; i < last; i++) { // 最后一行的单词
                    row += words[i];
                    if (i != last - 1){
                        row += " ";
                    }
                }
                while (row.size() < maxWidth){
                    row += " ";  // 单词加完了补空格
                }
            } 
            else {
                int spaces = (maxWidth - totalChars) / (wordCount - 1);
                int extraSpaces = (maxWidth - totalChars) % (wordCount - 1);
                
                for (int i = index; i < last; i++) {
                    row += words[i];
                    if (i != last - 1) {
                        row.append(spaces + 1, ' ');
                        if (extraSpaces-- > 0) row += " ";
                    }
                }
            }
            
            result.push_back(row);
            index = last;
        }
        
        return result;
    }
};
