class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    vector<int>ans;
    int n = potions.size();
    sort(potions.begin() , potions.end());
    for(int i : spells){
        long long  m = (success + i - 1  )/i;
        auto it = lower_bound(potions.begin() , potions.end() , m);
        int index = distance(potions.begin() , it);
        ans.push_back(n - index);
    }
    return ans;
    }
};