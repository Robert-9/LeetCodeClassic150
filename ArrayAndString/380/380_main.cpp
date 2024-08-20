/*
    你必须实现类的所有函数，并满足 每个 函数的平均时间复杂度为 O(1) 。
*/
#include <vector>
#include <unordered_map>
#include <time>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> hash;
    vector<int> vec;
public:
    RandomizedSet() {
        /*
            初始化 RandomizedSet 对象
        */
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        /*
            当元素 val 不存在时，向集合中插入该项，并返回 true ；否则，返回 false 。
        */
        if(hash.count(val)){  // find是用于查找元素在其中的位置，返回的是一个迭代器。此处应用count
            return false;
        }
        vec.push_back(val);
        int index = vec.size();
        hash[val] = index;
        return true;
    }
    
    bool remove(int val) {
        /*
            当元素 val 存在时，从集合中移除该项，并返回 true ；否则，返回 false 。
        */

        if(!hash.count(val)){
            return false;
        }

        int index = hash[val];
        int back = hash[vec.back()];

        vec[index] = vec.back();  // 覆盖index位置处的向量
        hash[back] = index;  // 修改back的值
        hash.erase(val);
        vec.pop_back();
        return true;
    }
    
    int getRandom() {
        /*
            随机返回现有集合中的一项（测试用例保证调用此方法时集合中至少存在一个元素）。每个元素应该有 相同的概率 被返回。
        */
        int randomIndex = rand()%vec.size();
        return vec[randomIndex];
    }
};