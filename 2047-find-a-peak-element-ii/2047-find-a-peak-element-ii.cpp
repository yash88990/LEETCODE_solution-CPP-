class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int left = 0 , right  = n - 1;
        while(left <= right){
            int mid = left + ( right - left) / 2 ;
            int maxrow = 0;
            for(int i = 1 ; i < n ; i++){
                if(mat[i][mid] > mat[maxrow][mid] ){
                    maxrow = i;
                }
            }
            int leftval = (mid - 1 >= 0)? mat[maxrow][mid - 1] : -1;
            int rightval = (mid + 1 < n) ? mat[maxrow][mid + 1] : -1;
            if(mat[maxrow][mid] > leftval && mat[maxrow][mid] > rightval){
                return {maxrow , mid};
            }else if(leftval > mat[maxrow][mid]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return {-1 ,-1};
    }
};