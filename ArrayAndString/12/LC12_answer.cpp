#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
private:
    multimap<int, string, greater<int>> valueKeyMap = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"},
        {5, "V"}, {4, "IV"}, {1, "I"}
    };

public:
    string intToRoman(int num) {
        string result;
        for (auto& pair : valueKeyMap) {
            while (num >= pair.first) {
                num -= pair.first;
                result += pair.second;
            }
        }
        return result;
    }
};
