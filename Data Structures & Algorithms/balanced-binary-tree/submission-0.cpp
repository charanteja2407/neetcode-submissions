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
    bool isBalanced(TreeNode* root) {

        return isb(root) != -1;
    }

private:
    int isb(TreeNode* root){
        if(!root) return 0;

        int lh = isb(root -> left);
        if(lh == -1) return -1;

        int rh = isb(root -> right);
        if(rh == -1) return -1;
        
        if(abs(rh - lh) > 1) return -1;

        return 1 + max(lh, rh);
    }
};
