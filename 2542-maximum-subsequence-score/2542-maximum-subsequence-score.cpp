class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>>zipped(n);
        for(int i = 0 ; i < n ; i++){
            zipped[i] = {nums2[i] , nums1[i]};
        }
        sort(zipped.rbegin() , zipped.rend());
        long long  sum = 0 ,maxi = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto &pair : zipped){
            int num2 = pair.first;
            int num1 = pair.second;
            pq.push(num1);
            sum += num1;
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k){
                maxi = max(maxi , sum * num2);
            }
            

        }
        return maxi;
    }
};