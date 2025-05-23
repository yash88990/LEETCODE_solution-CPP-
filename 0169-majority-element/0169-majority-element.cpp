class Solution {
public:
    int majorityElement(vector<int>& ans) {
        int n = ans.size();
        sort(ans.begin() , ans.end());
        return ans[n/2];
    }
};