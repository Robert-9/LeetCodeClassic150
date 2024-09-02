/*
    给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。

    你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。

    要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

    文本的最后一行应为左对齐，且单词之间不插入额外的空格。



    测试已通过！  
        但与answer相比漏洞太多，思路虽然大体相近，但一直不能通过测试。
        调试了了将近一天才修补完所有的情况。
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        int index = 0;
        vector<string> result;
        while (index < words.size()) {
            int cnt = 1 + words[index].size(); // 用于保存一行的字符数
            int i = 0;                         // 实际为单词数

            while (cnt <= maxWidth + 1 && (index + i) < words.size()) {
                i++;
                if (index+i <  words.size()) {
                    cnt +=
                        (1 + words[index + i].size()); // answer中先判断加了之后是否还比maxWidth小，小才加，大则break
                                                       // 这样就不用在后面再减了
                }
            }

            string row;
            if (cnt >= maxWidth && i != 1 && (index + i) < words.size()) {
                cnt -= (i + words[index + i].size() + 1);
                int extraSpace = (maxWidth - cnt) % (i - 1);
                int spaceNum = (maxWidth - cnt) / (i - 1);

                for (int j = 0; j < i; j++) {
                    row += words[index + j];
                    if (j != i - 1) {
                        row.append(spaceNum, ' ');
                    }
                    if (extraSpace-- > 0) {
                        row += ' ';
                    }
                }
                index += i;
            } else {
                while (index < words.size() && i > 0) {
                    row += words[index++];
                    row += " ";
                    i--;
                }
                while (row.size() < maxWidth) {
                    row += " ";
                }
                if (row.size() > maxWidth) {
                    row.pop_back();
                }
            }

            result.push_back(row);
        }

        return result;
    }
};


int main(){
    Solution solution;
    // vector<string> input = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    // vector<string> input = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> input = {"a"};
    vector<string> res = solution.fullJustify(input, 1);
    for(int i=0; i<res.size(); i++){
        cout<< res[i] << endl;
    }
}
