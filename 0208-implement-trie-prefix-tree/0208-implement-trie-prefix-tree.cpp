class TrieNode{
public:
    TrieNode* children[26];
    bool isend;
    TrieNode(){
        isend = false;
        for(int i = 0 ; i < 26 ; i++)children[i] = nullptr;
    }
};



class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char ch : word){
            int index = ch - 'a';
            if(curr->children[index] == NULL){
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isend = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char ch : word){
            int index = ch - 'a';
            if(curr->children[index] == NULL)return false;
            curr = curr->children[index];
        }
        return curr->isend;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char ch : prefix){
            int index = ch - 'a';
            if(curr->children[index] == NULL)return false;
            curr = curr->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */