class Solution {
public:
    bool can(vector<int>& weights, int days , int capacity){
        int daycount =1;
        int currload = 0;
        for(int w : weights){
            if(currload  + w > capacity){
                daycount++;
                currload = 0;
            }
            currload += w;
        }
        return daycount <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin() , weights.end());
        int r =  accumulate(weights.begin() , weights.end() , 0);
        int ans = r;
        while(l <= r ){
            int m = l + ( r - l)/2;
            if(can(weights , days , m)){
                ans =m ;
                r = m - 1;
            }else l = m + 1 ;
        }
        return ans;
        
    }
};