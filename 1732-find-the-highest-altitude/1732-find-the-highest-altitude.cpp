class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0 , maxi = 0;
        for(int num : gain){
            curr += num;
            maxi = max(maxi , curr);
        }
        return maxi;
    }
};