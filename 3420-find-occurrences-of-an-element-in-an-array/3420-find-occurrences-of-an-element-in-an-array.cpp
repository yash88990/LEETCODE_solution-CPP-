class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> xIndices;
        
        // Step 1: Store all indices where nums[i] == x
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == x) {
                xIndices.push_back(i);
            }
        }

        // Step 2: Answer each query
        vector<int> answer;
        for (int q : queries) {
            if (q <= xIndices.size()) {
                answer.push_back(xIndices[q - 1]); // 1-based occurrence index
            } else {
                answer.push_back(-1);
            }
        }

        return answer;
    }
};
