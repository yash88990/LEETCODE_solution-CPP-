/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
                 //  node           hd   lvl
        queue<pair<TreeNode* , pair<int,int>>> q;

        // hd         lvl      nodes
        map<int , map<int, vector<int>>> nodes;
        q.push(make_pair(root , make_pair(0 , 0)));
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp = q.front();
            q.pop();
            TreeNode* frontnode = temp.first;
            int hd = temp.second.first;
            int lvl =temp.second.second;
            nodes[hd][lvl].push_back(frontnode->val);
            if(frontnode->left)q.push(make_pair(frontnode->left , make_pair(hd - 1 , lvl + 1)));
            if(frontnode->right)q.push(make_pair(frontnode->right, make_pair(hd +1 , lvl + 1)));
        }
        for(auto i : nodes){
            vector<int>col;
            for(auto j : i.second){
                vector<int>temp = j.second;
                sort(temp.begin() , temp.end());
                col.insert(col.end() , temp.begin() , temp.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};