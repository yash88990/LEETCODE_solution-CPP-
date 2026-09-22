class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result={{}};
        for (int num : nums) {
            vector<vector<int>> next;
            for (auto perm : result) {
                for (int i = 0; i <= perm.size(); i++) {
                    vector<int> temp = perm;
                    temp.insert(temp.begin() + i, num);
                    next.push_back(temp);
                }
            }
            result = next;
        }

        return result;
    }
};