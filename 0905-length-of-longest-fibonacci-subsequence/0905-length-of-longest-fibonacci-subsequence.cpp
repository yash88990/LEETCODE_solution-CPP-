class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int>  s(arr.begin() , arr.end());
        int n = arr.size() , maxlength = 0;
        for(int i = 0 ; i <n ; i++){
            for(int j = i+1 ; j <n ; j++){
                int x = arr[i] , y = arr[j] , length = 2;
                while(s.count(x+y)){
                    int temp = y ;
                    y = x+y;
                    x = temp;
                    length++;
                }
                maxlength = max(length , maxlength );
            }
        }
        return maxlength >= 3 ? maxlength : 0;
    }
};