class Solution {
public:
    bool canfinish(vector<int>& piles, int h , int k){
        int hour = 0;
        for(int bananas : piles){
            hour += (bananas + k - 1)/k;
        }
        return hour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1 ;
        int end = *max_element(piles.begin() , piles.end());
        while(start < end){
            int mid = start + ( end - start)/2;
            if(canfinish(piles , h , mid)){
                end = mid;
            }else start = mid + 1 ;
        }
        return start;
    }
};