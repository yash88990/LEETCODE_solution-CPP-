class Solution {
public:
    bool caneat(vector<int>piles , int h , int mid){
        int hour = 0;
        for(int banana : piles){
            hour += (banana + mid - 1 )/mid;
        }
        return hour <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start =1 , end = *max_element(piles.begin() , piles.end());
        while( start < end){
            int mid = start + ( end - start)/2;
            if(caneat(piles , h , mid)){
                end = mid;
            }else start = mid + 1 ;
        }
        return start;
    }
};