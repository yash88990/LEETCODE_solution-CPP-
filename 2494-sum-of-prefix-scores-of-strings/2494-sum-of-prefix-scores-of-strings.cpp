class Solution {
public:
    // Trie Node structure to store prefix counts
    struct TrieNode {
        TrieNode* children[26] = {nullptr};  // Each node has 26 children (for each lowercase letter)
        int count = 0;  // How many words share this prefix
    };
    
    // Function to insert a word into the Trie and update prefix counts
    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            node->count++;  // Increment the prefix count
        }
    }
    
    // Function to calculate the sum of prefix scores for a word
    int getPrefixScore(TrieNode* root, const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                break;
            }
            node = node->children[idx];
            score += node->count;  // Add the count of words sharing this prefix
        }
        return score;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        
        // Insert all words into the Trie
        for (const string& word : words) {
            insert(root, word);
        }
        
        // For each word, compute the sum of prefix scores
        vector<int> result;
        for (const string& word : words) {
            result.push_back(getPrefixScore(root, word));
        }
        
        return result;
    }
};
