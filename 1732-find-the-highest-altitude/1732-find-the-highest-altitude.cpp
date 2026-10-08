class Solution {
public:
    int largestAltitude(vector<int>& nums) {
        int currsum = 0 , maxi = 0;
        for(int num : nums){
            currsum += num;
            maxi = max(maxi , currsum);
        }
        return maxi;
    }
};