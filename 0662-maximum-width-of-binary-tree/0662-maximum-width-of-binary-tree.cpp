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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int maxwidth = 0;
        queue<pair<TreeNode* , long long >> q;
        q.push({root , 0});
        while(!q.empty()){
            int size = q.size();
            long long leftindex = q.front().second;
            long long  first = 0 , last = 0;
            for(int i =0 ;i < size; i++){
                auto[node , index] = q.front();
                q.pop();
                index -= leftindex;

                if(i == 0)first = index;
                if(i == size-1)last = index;
                if(node->left)q.push({node->left ,2 * index });
                if(node->right)q.push({node->right , 2 * index + 1} );
            }
            maxwidth = max(maxwidth , static_cast<int>(last - first + 1));
        }
        return maxwidth;
        
    }
};