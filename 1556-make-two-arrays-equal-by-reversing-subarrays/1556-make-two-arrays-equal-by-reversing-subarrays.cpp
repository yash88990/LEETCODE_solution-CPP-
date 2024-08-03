#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (target.size() != arr.size()) {
            return false;
        }
        
        unordered_map<int, int> targetCount;
        unordered_map<int, int> arrCount;
        
        for (int i = 0; i < target.size(); ++i) {
            ++targetCount[target[i]];
            ++arrCount[arr[i]];
        }
        
        return targetCount == arrCount;
    }
};
