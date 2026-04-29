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
    void parseTree(TreeNode* root, string &s){

        if(!root){
            s+= "x,";
            return;
        }

        s += to_string(root->val) +",";
        parseTree(root->left, s);
        parseTree(root->right, s);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(subRoot == nullptr) return true;
        if(root == nullptr) return false;

        string roots = "";
        string subroots = "";

        parseTree(root, roots);
        parseTree(subRoot, subroots);

        cout << roots << endl;
        cout << subroots << endl;

        return (roots.find(subroots) != std::string::npos);
    }
};
