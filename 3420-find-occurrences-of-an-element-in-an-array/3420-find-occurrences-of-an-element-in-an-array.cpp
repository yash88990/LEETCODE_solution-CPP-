class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>ans;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == x)ans.push_back(i);
        }
        vector<int>result;
        for(int q : queries){
            if(q <= ans.size()){
                result.push_back(ans[q - 1]);
            }else{
                result.push_back(-1);
            }
        }
        return result;
    }
};