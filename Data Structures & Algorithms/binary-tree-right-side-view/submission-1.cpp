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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)   return res;
        
        queue<TreeNode* >q;
        q.push(root);
        res.push_back(root->val);

        while(!q.empty()){
            int t = q.size();
            
            int k = -1;
            while(t--){
                TreeNode* curr = q.front();
                q.pop();
                cout << curr -> val << ' ';
                if(curr -> left){
                    k = curr -> left -> val;
                    q.push(curr -> left);
                } 
                if(curr -> right){
                    k = curr -> right -> val;
                    q.push(curr -> right);
                }  
                
            }

            cout << endl;
            if(k != -1)
            res.push_back(k);
        }

        return res;
        
    }
};
