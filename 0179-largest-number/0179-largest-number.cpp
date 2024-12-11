class Solution {
public:
static bool compare ( string a , string b ){
    return a+b > b + a;
}
    string largestNumber(vector<int>& nums) {
        // convert into strings
        vector<string> str_nums;
        for(int num : nums){
            str_nums.push_back(to_string(num));
        }
        //sort
        sort(str_nums.begin() , str_nums.end() , compare);
        
        if(str_nums[0] == "0" ){
            return "0";
        }

        string result = "";
        for(string num : str_nums){
            result += num;
        }
        return result;

    }
};