class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        //step 1 
        for(int num : nums){
            if(num < k)return -1;
        }
        //step2 
        unordered_set<int> s;
        for(int num : nums){
            if(num > k)s.insert(num);
        }
        //step3;
        return s.size();
    }
};