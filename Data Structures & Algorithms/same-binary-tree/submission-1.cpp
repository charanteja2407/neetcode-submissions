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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // {{Cases that needed to be covered}}
        // where both are nullptr
        // either of them is nullptr
        // values at certain traversal are not equal
        // left or right childs of correspondings nodes are not equal
        
        // cout << p -> val << ' ' << q -> val << endl;
        if(!p && !q)  return true;
        if(!p || !q)  return false;
        // if(!q)  return false;

        queue<TreeNode*> queue1, queue2;

        queue1.push(p);
        queue2.push(q);
        // cout << p -> val << ' ' << q -> val << endl;

        while(!queue1.empty() && !queue2.empty()){

            TreeNode* a = queue1.front();
            TreeNode* b = queue2.front();
            cout << a -> val << ' ' << b -> val << endl;
            queue1.pop();
            queue2.pop();

            if(a -> val != b -> val)  return false;
            if((a -> left != nullptr) != (b -> left!= nullptr))  return false;
            if((a -> right!= nullptr) != (b -> right!= nullptr))  return false;

            if(a -> left){
            queue1.push(a -> left);
            queue2.push(b -> left);
            }

            if(b -> right){
            queue1.push(a -> right);
            queue2.push(b -> right);
            }

        }

        return queue1.empty() && queue2.empty();
    }
};
