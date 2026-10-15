class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        // while(k>0){
        //     int temp = arr[arr.size()-1];
        //     for(int i = arr.size() - 1 ; i > 0 ; i--){
        //         arr[i] = arr[i-1];
        //     }
        //     arr[0] = temp;
        //     k--;
        // }

        int n = arr.size();
        k = k % n;
        reverse(arr.begin() , arr.end());
        reverse(arr.begin() , arr.begin() + k);
        reverse(arr.begin() + k , arr.end());


    }
};