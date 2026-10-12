class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //step 1 create min pq
        priority_queue<int,vector<int>,greater<int>>min_pq;
        //step 2 traverse arr and insert k elem in pq
        for(int i = 0 ; i < k ; i++){
            min_pq.push(nums[i]);
        }
        //step 3 trverse k to n and compare and push or pop
        for(int i = k ; i < nums.size() ; i++){
            if(nums[i] > min_pq.top()){
                min_pq.pop();
                min_pq.push(nums[i]);
            }
        }
        return min_pq.top();
    }
};