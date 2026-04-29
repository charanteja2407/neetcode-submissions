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
    int goodNodes(TreeNode* root) {
        
        return dfs(root, INT_MIN);
    }

    int dfs(TreeNode* node, int maxSoFar){
        if(!node) return 0;

        int count = (node -> val >= maxSoFar);

        return count + dfs(node -> left, max(maxSoFar, node -> val))
        + dfs(node -> right, max(maxSoFar, node -> val));
    }
};
