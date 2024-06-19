class Solution {
public:
bool canMakeBouquetes(vector<int>&bloomDay, int m , int k , int day){
    int flowers = 0 ;
    int bouquetes = 0 ;
    for(int bloom : bloomDay){
        if(bloom <= day ){
            flowers++;
            if(flowers == k ){
                bouquetes++;
                flowers = 0;
            }
        }else{
            flowers = 0 ;
        }
    }
        return bouquetes >= m ;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size() ;
        if(static_cast < long long > (m) * k > n ) return -1 ;
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin() , bloomDay.end() );
        while(left <= right ){
            int mid = left + ( right - left ) / 2 ;
            if ( canMakeBouquetes(bloomDay , m , k , mid)){
                right = mid -1 ;

            }else{
                left = mid + 1 ;
            }
        }
        return left ;
    }
};