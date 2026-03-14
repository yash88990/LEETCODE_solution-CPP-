class Solution {
public:
    void generateHappyStrings(int n, string &current, vector<string> &result, char lastChar) {
        if (current.size() == n) {
            result.push_back(current);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (ch != lastChar) { // Ensure it's a happy string
                current.push_back(ch);
                generateHappyStrings(n, current, result, ch);
                current.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        string current = "";
        generateHappyStrings(n, current, happyStrings, '\0');

        return (happyStrings.size() >= k) ? happyStrings[k - 1] : "";
    }
};
