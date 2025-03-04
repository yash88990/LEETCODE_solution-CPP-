#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parentMap;  // Maps each node to its parent

    void buildGraph(TreeNode* root, TreeNode* parent) {
        if (!root) return;
        if (parent) parentMap[root] = parent;  // Map child to parent
        buildGraph(root->left, root);
        buildGraph(root->right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Step 1: Convert tree into graph
        buildGraph(root, nullptr);

        // Step 2: BFS from target node
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        
        int distance = 0;
        while (!q.empty()) {
            if (distance == k) break;  // Stop when we reach distance k
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                
                // Push all unvisited neighbors (left, right, parent)
                if (node->left && !visited.count(node->left)) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && !visited.count(node->right)) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (parentMap.count(node) && !visited.count(parentMap[node])) {
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                }
            }
            distance++;
        }

        // Collect all nodes at distance k
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }
};
