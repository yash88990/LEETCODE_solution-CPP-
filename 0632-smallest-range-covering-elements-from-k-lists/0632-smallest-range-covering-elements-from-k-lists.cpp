class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int currentmax= INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            pq.push({nums[i][0] , i , 0});
            currentmax= max(currentmax , nums[i][0]);
        }
        int rangestart = 0 , rangeend = INT_MAX;
        while(pq.size() == nums.size()){
            auto curr = pq.top();
            pq.pop();
            int val = curr[0] ;
            int listindex = curr[1];
            int eleindex = curr[2];
            if(currentmax - val < rangeend - rangestart){
                rangestart = val;
                rangeend = currentmax;
            }
            if(eleindex + 1 < nums[listindex].size()){
                int nextval = nums[listindex][eleindex + 1 ];
                pq.push({nextval , listindex , eleindex + 1 });
                currentmax = max(currentmax , nextval);

            }else break;
        }
        return {rangestart , rangeend};
    }
};