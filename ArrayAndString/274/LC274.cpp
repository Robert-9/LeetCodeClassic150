/*
    给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数。计算并返回该研究者的 h 指数。
    根据维基百科上 h 指数的定义：
        h 代表“高引用次数”，是指至少发表了 h 篇论文，并且至少有 h 篇论文被引用次数大于等于 h 。
        如果 h 有多种可能的值，h 指数 是其中最大的那个。

    倒序排序一下，再根据 下标+1 和 元素值 比大小
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
private:
    void quickSort(vector<int>& array, int left, int right){
        int i = left;
        int j = right;
        if(i >= j) return ;

        int pivot = array[left];
        while(i != j){
            while(array[j]<=pivot && i<j){
                j--;
            }
            array[i] = array[j];
            while(array[i]>=pivot && i<j){
                i++;
            }
            array[j] = array[i];
        }
        array[i] = pivot;
        quickSort(array, left, i - 1);
        quickSort(array, i + 1, right);
    }
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;

        quickSort(citations, 0, citations.size()-1);
        int i = 0;
        while (i + 1 <= citations[i] && i < citations.size()) {
            i++;
        }
        return i;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {3, 0, 4, 1, 6, 5, 2};

    int res = solution.hIndex(nums);

    cout<< res;
}