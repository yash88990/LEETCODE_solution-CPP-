class Solution {
public:
    bool solve(vector<int>& bloomDay, int m, int k, int mid) {
        int f = 0;
        int b = 0;
        for(int bloom : bloomDay){
            if(bloom <= mid){
                f++;
                if(f == k){
                    b++;
                    f = 0;
                }
            }else f = 0;
        }
        return b >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int ans = -1;
        if((1LL * m * k) > n)return -1;
        int left = *min_element(bloomDay.begin() , bloomDay.end());
        int right = *max_element(bloomDay.begin() , bloomDay.end());
        while( left <= right){
            int mid = left + ( right - left)/2;
            if(solve(bloomDay , m , k , mid)){
                ans = mid;
                right = mid - 1;
            }else left = mid + 1 ;
        }
        return ans;
    }
};