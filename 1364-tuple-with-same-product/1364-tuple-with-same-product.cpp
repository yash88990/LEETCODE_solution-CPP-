class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> productcount ;
        int count = 0;
        int n = nums.size();
        for(int i = 0 ;i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                int product = nums[i] * nums[j];
                productcount[product]++;
            }
        }
        for(auto & [product , freq] : productcount){
            if(freq > 1 ){
                count += (freq * (freq - 1 ) / 2 ) * 8 ;
            }
        }
        return count ;
    }
};