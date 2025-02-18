class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(int num : nums)freq[num]++;
        // for(int num : nums){
        //     if(freq[num] > n/ 2 ) return num;
        // }
        int ans ;
        for(auto &entry : freq){
            if(entry.second > n/2){
                ans = entry.first;
            }
        }
        return ans;
        
    }
};