/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode* , TreeNode*> parentMap;
    void buildGraph(TreeNode* root , TreeNode* parent){
        if(!root)return;
        if(parent)parentMap[root] = parent;
        buildGraph(root->left , root );
        buildGraph(root->right , root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildGraph(root , NULL);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int distance = 0;
        while(!q.empty()){
            if(distance == k)break;
            int size = q.size();
            for(int i = 0 ; i < size; i++){
                TreeNode* node = q.front() ; q.pop();
                if(node->left  && !visited.count(node->left)){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                 if(node->right  && !visited.count(node->right)){
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if(parentMap.count(node) && !visited.count(parentMap[node])){
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }
            distance++;
        }
        vector<int>result;
        while(!q.empty()){
            result.push_back(q.front() ->val);
            q.pop();
        }
        return result;

        
    }
};











