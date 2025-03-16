class Solution {
public:
    bool ispossible(long long time , vector<int>& ranks, int cars){
        long long totalcars = 0;
        for(int r : ranks){
            long long n = sqrt(time / r);
            totalcars += n;
            if(totalcars >= cars )return true;
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = 1e14 , answer = -1;
        while(left <= right){
            long long mid = left + ( right - left)/2;
            if(ispossible(mid , ranks , cars)){
                answer = mid;
                right = mid -1 ;
            }else{
                left = mid + 1 ;
            }
        }
        return answer;
    }

};