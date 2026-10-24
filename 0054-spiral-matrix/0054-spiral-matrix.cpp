class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int r = matrix.size();
        int c = matrix[0].size();
        int top = 0 , left = 0 , bottom = r-1 , right = c-1;
        while(left <= right && top <= bottom){
            //left to right
            for(int col = left ; col <= right ; col++){
                ans.push_back(matrix[top][col]);

            }
            top++;
            //top to bottom
            for(int row = top ; row <= bottom ; row++){
                ans.push_back(matrix[row][right]);

            }
            right--;
            //right to left 
            if(top <= bottom){
                for(int col = right ; col >= left ; col--){
                    ans.push_back(matrix[bottom][col]);

                }
                bottom--;
            }
            //bottom to top
            if(left <= right){
                for(int row = bottom ; row >= top ; row--){
                    ans.push_back(matrix[row][left]);

                }
                left++;

            }
        }
        return ans;
    }
};