class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int,int> freq;
        // for(int num : nums)freq[num]++;
        // int maxi = INT_MIN;
        // int ans = -1;
        // for(auto &entry : freq){
        //     if(entry.second  > maxi){
        //         maxi = entry.second;
        //         ans = entry.first;
        //     }
        // }
        // return ans;



        sort(nums.begin() , nums.end());
        return nums[nums.size() / 2];
    }
};