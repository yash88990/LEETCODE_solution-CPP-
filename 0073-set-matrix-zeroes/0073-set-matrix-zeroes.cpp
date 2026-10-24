class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstrowzero = false;
        bool firstcolzero = false;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0 ; i < n ; i++){
            if(matrix[i][0] == 0 ){
                firstcolzero = true;
                break;
            }
        }
        for(int i = 0 ; i < m ; i++){
            if(matrix[0][i] == 0 ){
                firstrowzero = true;
                break;
            }
        }
        for(int i = 1 ; i < n; i++){
            for(int j = 1 ; j < m ; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1 ; i < n ; i++){
            for(int j  = 1 ; j < m ; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstrowzero){
            for(int i = 0 ; i <m; i++){
                matrix[0][i] = 0;
            }
        }

        if(firstcolzero){
            for(int i = 0 ; i < n ; i++){
                matrix[i][0] = 0;
            }
        }
    }
};