class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0 , end = arr.size() ;
        while(start < end){
            int mid = start + ( end - start) / 2;
            int missing = arr[mid] - mid  - 1;
            if(missing < k)start = mid + 1;
            else end = mid;
        }
        return start + k;
    }
};