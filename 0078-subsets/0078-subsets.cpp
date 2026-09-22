class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result={{}};
        for(int num:nums){
            vector<vector<int>>next;
            for(auto subset : result){
                vector<int>temp=subset;
                temp.push_back(num);
                next.push_back(temp);
            }
            for(auto subset : next)result.push_back(subset);
        }
        return result;
    }
};