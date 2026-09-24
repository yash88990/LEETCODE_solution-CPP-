class Solution {
public:
    bool canmake(vector<int>& bloomDay, int m, int k , int day){
        int flower = 0 , bouquets = 0;
        for(int bloom : bloomDay){
            if(bloom <= day){
                flower++;
                if(flower == k){
                    bouquets++;
                    flower = 0;
                }
            }else{
                flower = 0;
            }
        }
        return bouquets >= m ;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size())return -1;
        int left = *min_element(bloomDay.begin() , bloomDay.end());
        int right = *max_element(bloomDay.begin() , bloomDay.end());
        int ans= -1;
        while(left <= right){
            int mid = left + ( right - left)/2;
            if(canmake(bloomDay , m , k , mid)){
                ans = mid ;
                right = mid - 1 ;
            }else left = mid + 1 ;
        }
        return ans;
    }
};