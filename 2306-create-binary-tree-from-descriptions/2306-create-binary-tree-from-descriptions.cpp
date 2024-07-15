
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        // Step 1: Create all nodes and establish parent-child relationships
        for (const auto& desc : descriptions) {
            int parentVal = desc[0], childVal = desc[1], isLeft = desc[2];
            if (nodes.find(parentVal) == nodes.end()) {
                nodes[parentVal] = new TreeNode(parentVal);
            }
            if (nodes.find(childVal) == nodes.end()) {
                nodes[childVal] = new TreeNode(childVal);
            }

            if (isLeft) {
                nodes[parentVal]->left = nodes[childVal];
            } else {
                nodes[parentVal]->right = nodes[childVal];
            }
            
            children.insert(childVal);
        }

        // Step 2: Identify the root node (node with no parent)
        TreeNode* root = nullptr;
        for (const auto& node : nodes) {
            if (children.find(node.first) == children.end()) {
                root = node.second;
                break;
            }
        }

        return root;
    }
};
