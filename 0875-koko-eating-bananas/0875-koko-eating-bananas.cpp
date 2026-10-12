class Solution {
public:
    bool canfinish(vector<int>&piles , int h , int k){
        int hours = 0;
        for(int i : piles){
            hours += (i + k - 1)/k;
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1 , end = *max_element(piles.begin() , piles.end());
        int ans = end;
        while(start < end){
            int mid = start + ( end - start)/2 ;
            if(canfinish(piles , h , mid)){
                ans = mid;
                end = mid;
            }else start = mid + 1 ;
        }
        return ans;
    }
};