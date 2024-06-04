class Solution {
public:
    bool isIsomorphic(string s, string t) {
         // Check if lengths of strings are different, return false if so
        if (s.length() != t.length())
            return false;
        
        // Create two maps to store the mappings of characters
        std::unordered_map<char, char> s_to_t;
        std::unordered_map<char, char> t_to_s;
        
        // Iterate through each character of the strings
        for (int i = 0; i < s.length(); ++i) {
            char s_char = s[i];
            char t_char = t[i];
            
            // If s_char is already mapped to a different character in t
            if (s_to_t.find(s_char) != s_to_t.end() && s_to_t[s_char] != t_char)
                return false;
            
            // If t_char is already mapped to a different character in s
            if (t_to_s.find(t_char) != t_to_s.end() && t_to_s[t_char] != s_char)
                return false;
            
            // Update the mappings
            s_to_t[s_char] = t_char;
            t_to_s[t_char] = s_char;
        }
        
        return true;
    }
};