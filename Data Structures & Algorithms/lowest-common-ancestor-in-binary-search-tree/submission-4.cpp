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

        // if( (q -> val < root -> val && root -> val < p -> val ) ||
        // (p -> val < root -> val && root -> val < q -> val )|| 
        // (p -> val == root -> val || q -> val == root -> val)) 
        //     return root;
        // else 
    // a r b -- a and b are values of p and q respectively
    // if a < r && r < b then return r
    // if a < r && b < r then lca(r->left, p, q);
    // if r < a && r < b then lca(r->right, p, q);

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root == nullptr)  return nullptr;
    //    if(p == nullptr || q == nullptr) return nullptr;

        cout << root -> val << ' ' << p -> val << ' ' << q -> val << endl;        
        if(p -> val < root -> val &&  q -> val < root -> val) {
            cout << "left:" << endl;
            return lowestCommonAncestor(root-> left, p, q);
        }
        else if( root -> val < p -> val && root -> val < q -> val){
            cout << "right:" << endl;
            return lowestCommonAncestor(root-> right, p, q);
        }
        else
        return root;
    }
};
