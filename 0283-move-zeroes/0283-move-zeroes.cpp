class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size() ;
        int nonzeroindex = 0 ;
        for ( int i  =  0 ; i < n ; i++ ){
            if ( nums[i] != 0 ){
                nums[nonzeroindex] = nums[i] ;
                nonzeroindex++ ;
            }
        }
        for(int i = nonzeroindex ; i < n ; i++ ){
            nums[i] = 0 ;
        }
        
    }
};