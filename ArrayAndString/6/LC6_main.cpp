/*
    将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        int cur = 0;
        int row = 1;
        int flag = 0;
        vector<int> rowVec;
        while(cur++ < s.size() ){
           
            rowVec.push_back(row);
            if(flag == 0) row++;
            else if(flag == 1) row--;
            
            if(row >= numRows) flag = 1;
            else if(row <= 1) flag = 0;
        }
        for(int i=1; i<=numRows; i++ ){
            for(int j=0; j < s.size(); j++){
                if(rowVec[j] == i){
                    result += s[j];
                }
            }
        }
        return result;
    }
};


int main(){
    Solution solution;
    string s = "AB";
    string res = solution.convert(s, 1);
    cout<< res;
}