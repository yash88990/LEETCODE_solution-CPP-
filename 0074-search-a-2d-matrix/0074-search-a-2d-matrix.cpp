class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
        return false;
        int rows = matrix.size();
        int coln = matrix[0].size() ;
        int left = 0 ;
        int right = rows * coln - 1 ;
        while(left <= right ){
            int mid = left + (right - left ) / 2 ;
            int mid_element =matrix[mid/coln][mid%coln] ;
            if(mid_element == target )
            return true ;
            else if (mid_element < target )
            left = mid + 1 ;
            else
            right = mid - 1 ;
        }
        return false ;
        
    }
};