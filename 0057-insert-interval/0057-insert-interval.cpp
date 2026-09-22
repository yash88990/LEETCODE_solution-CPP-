class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         
         intervals.push_back(newInterval);
         int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i = 1 ; i <  n ; i++){
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