/*
    罗马数字包含以下七种字符: I， V， X， L，C，D 和 M

    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000

    通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例

    I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
    X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
    C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。

    测试已通过！
*/

#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
private:
    map<char, int> myMap;
    int result = 0;

    void mapInit(){
        myMap['I'] = 1;
        myMap['V'] = 5;
        myMap['X'] = 10;
        myMap['L'] = 50;
        myMap['C'] = 100;
        myMap['D'] = 500;
        myMap['M'] = 1000;
    }
public:
    int romanToInt(string s) {
        if(s.empty()) return 0;

        mapInit();
        int len = s.size();

        for(int i=0; i<len; i++){
            if(i != len-1 && myMap[s[i]] < myMap[s[i+1]]){
                result = result - myMap[s[i]];
            }
            else{  // 当前位置代表的数大于等于后面的数
                result = result + myMap[s[i]];
            }
        }
        return result;
    }
};