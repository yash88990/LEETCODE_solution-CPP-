#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    vector<string> suggestions;
    
    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
            node->suggestions.push_back(word);
        }
    }
    
    vector<string> search(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx])
                return {};
            node = node->children[idx];
        }
        sort(node->suggestions.begin(), node->suggestions.end());
        return {node->suggestions.begin(), node->suggestions.begin() + min(3, (int)node->suggestions.size())};
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        vector<vector<string>> result;
        
        sort(products.begin(), products.end());
        for (const string& product : products)
            trie.insert(product);
        
        string prefix;
        for (char c : searchWord) {
            prefix += c;
            result.push_back(trie.search(prefix));
        }
        
        return result;
    }
};