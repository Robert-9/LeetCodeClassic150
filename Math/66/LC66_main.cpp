#include "../head_math.h"

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i=digits.size()-1; i>=0; i--) {
            if(carry == 0) break;
            digits[i] += carry;
            if(digits[i] > 9) {
                digits[i] -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        if(carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};