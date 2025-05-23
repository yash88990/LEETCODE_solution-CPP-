class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1 ;i < intervals.size() ; i++){
            vector<int> &lastinterval = ans.back();
            if(intervals[i][0] <= lastinterval[1]){
                lastinterval[1] = max(lastinterval[1] , intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};