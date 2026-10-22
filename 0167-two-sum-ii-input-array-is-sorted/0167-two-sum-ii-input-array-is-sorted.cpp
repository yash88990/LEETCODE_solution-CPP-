class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        int i = 0 , j = n.size()-1;
        vector<int>ans;
        while(i < j ){
            int sum = n[i] + n[j];
            if(sum == t){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }else if(sum > t){
                j--;
            }else i++;
        }
        return ans;
        
    }
};