
class Solution {
public:
    static bool compare(string a, string b) {
        // Compare concatenated strings in both orders (a + b) and (b + a)
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        // Convert integers to strings
        vector<string> str_nums;
        for (int num : nums) {
            str_nums.push_back(to_string(num));
        }

        // Sort using custom comparator
        sort(str_nums.begin(), str_nums.end(), compare);

        // Edge case: if the largest number is "0", return "0"
        if (str_nums[0] == "0") {
            return "0";
        }

        // Concatenate the result
        string result = "";
        for (string num : str_nums) {
            result += num;
        }

        return result;
    }
};

