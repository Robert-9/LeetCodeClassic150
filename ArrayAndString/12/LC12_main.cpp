/*
    罗马数字是通过添加从最高到最低的小数位值的转换而形成的。将小数位值转换为罗马数字有以下规则：

    如果该值不是以 4 或 9 开头，请选择可以从输入中减去的最大值的符号，将该符号附加到结果，减去其值，然后将其余部分转换为罗马数字。
    如果该值以 4 或 9 开头，使用 减法形式，表示从以下符号中减去一个符号，例如 4 是 5 (V) 减 1 (I): IV ，9 是 10 (X) 减 1 (I)：IX。仅使用以下减法形式：4 (IV)，9 (IX)，40 (XL)，90 (XC)，400 (CD) 和 900 (CM)。
    只有 10 的次方（I, X, C, M）最多可以连续附加 3 次以代表 10 的倍数。你不能多次附加 5 (V)，50 (L) 或 500 (D)。如果需要将符号附加4次，请使用 减法形式。
    给定一个整数，将其转换为罗马数字。
*/

#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
private:
    map<char, int> myMap = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}, 
    };
    multimap<int, char, greater<int>> valueKeyMap = {
        {1, 'I'}, {5, 'V'}, {10, 'X'}, {50, 'L'}, {100, 'C'}, {500, 'D'}, {1000, 'M'}, 
    };


    string getOneRoman(int k, int base){
        string resStr;
         if(k == 4){ // 题目输入最大限制在3999
            if(base == 1){
                return "IV";
            } else if(base == 10){
                return "XL";
            } else {
                return "CD";
            }
        } else if(k == 9){
            if(base == 1){
                return "IX";
            } else if(base == 10){
                return "XC";
            } else {
                return "CM";
            }
        } else if(k == 0){
            return "*";
        } else{
            k *= base;
            for(auto& pair:valueKeyMap){
                while(k>=pair.first){
                    k -= pair.first;
                    resStr += pair.second;
                }
                if(k == 0){
                    break;
                }

            }
        }
        return resStr;
    }
public:
    string intToRoman(int num) {
        int k=0;
        int base = 1;
        string s;
        while(num>0){
            k = num%10;
            
            string pb = getOneRoman(k, base);
            if(pb != "*"){
                s.insert(0, pb);
            }
            
            base *= 10;
            num  = num / 10;
        }
        return s;
    }
};


int main(){
    Solution solution;
    string res = solution.intToRoman(1994);
    cout<< res;
}