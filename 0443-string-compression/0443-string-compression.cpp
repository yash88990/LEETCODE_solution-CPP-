
class Solution {
public:
    int compress(vector<char>& chars) {
        // Pointer to write the compressed characters
        int write_idx = 0;
        // Pointer to read the original array
        int read_idx = 0;
        
        while (read_idx < chars.size()) {
            char current_char = chars[read_idx];
            int group_start_idx = read_idx;
            
            // Count consecutive repeating characters
            while (read_idx < chars.size() && chars[read_idx] == current_char) {
                read_idx++;
            }
            
            int count = read_idx - group_start_idx;
            
            // Write the character to the compressed array
            chars[write_idx++] = current_char;
            
            // If the group length is greater than 1, write the count
            if (count > 1) {
                string count_str = to_string(count);
                for (char digit : count_str) {
                    chars[write_idx++] = digit;
                }
            }
        }
        
        return write_idx;
    }
};
