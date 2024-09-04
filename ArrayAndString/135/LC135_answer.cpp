#include <vector>
#include <algorithm>

using namespace std;


/*
    时间复杂度O(n)
    时间复杂度O(n)
        可以反映每个孩子拿到了多少个糖果
*/
class Solution1 {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // 从左到右遍历
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // 从右到左遍历
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // 计算总糖果数
        int totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }

        return totalCandies;
    }
};

/*
    时间复杂度O(n)
    时间复杂度O(1)
        这个算法在处理 ratings[i] < ratings[i - 1] 的时候，通过递减序列的长度来增加 result，但并不能明确表示每个 i 位置上具体的糖果分配情况。
        换句话说，虽然 result 代表了总的最小糖果数，但它并不能反映每个孩子的具体糖果分配细节。
*/
class Solution2 {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int result = 1;
        int inc = 1, dec = 0; // 递增和递减的长度
        int prev = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                prev = ratings[i] == ratings[i - 1] ? 1 : prev + 1;
                result += prev;
                inc = prev;
            } 
            else {
                dec++;
                if (dec == inc) {
                    dec++;
                }
                result += dec;
                prev = 1;
            }
        }
        return result;
    }
};
