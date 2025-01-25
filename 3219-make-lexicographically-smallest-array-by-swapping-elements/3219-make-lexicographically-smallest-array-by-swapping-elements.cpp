class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> index(n);
        iota(index.begin() , index.end(), 0);
        sort(index.begin() , index.end(), [&](int i , int j){
            return nums[i] < nums[j];
        });
        vector<int> ans(n);
        for(int i = 0 ; i < n;){
            int j = i+1;
            while(j < n && nums[index[j]] - nums[index[j-1]] <= limit){
                j++;
            }
            vector<int> t(index.begin()  + i , index.begin() +j );
            sort(t.begin() , t.end());
            for(int k = i ; k < j ; k++ ){
                ans[t[k - i]] = nums[index[k]];

            }
            i = j ;
        }
        return ans;
        

        
    }
};