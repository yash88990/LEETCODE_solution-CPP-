class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans ;
        int row = matrix.size() , col = matrix[0].size() , count = 0 , total = row*col ;
        int startingrow = 0 , startingcol = 0 , endingrow = row-1 , endingcol = col-1 ;

        while(count < total ){
            for(int index = startingcol ; count<total && index <= endingcol ; index++ ){
                ans.push_back(matrix[startingrow][index]);
                count++;
            }
            startingrow++;

            for(int index = startingrow ; count < total && index <= endingrow ; index++ ){
                ans.push_back(matrix[index][endingcol]);
                count++;
            }
            endingcol--;

            for(int index = endingcol ; count<total && index >= startingcol ; index-- ){
                ans.push_back(matrix[endingrow][index]);
                count++;
            }
            endingrow--;
            for(int i = endingrow ; count < total && i >= startingrow ; i-- ){
                ans.push_back(matrix[i][startingcol]);
                count++;
            }
            startingcol++;
        }
        return ans ;
    }
};