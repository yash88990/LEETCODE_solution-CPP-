#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            // Count the number of 1's in the binary representation of i
            ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans;
    }
};