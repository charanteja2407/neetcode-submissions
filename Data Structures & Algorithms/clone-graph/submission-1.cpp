/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(!node)   return nullptr;

        unordered_map<Node*, Node*> cloneOf;

        // think why?
        // Node* clone = new Node(node -> val);
        // cloneOf[node] = clone;

        dfs(node, cloneOf);

        return cloneOf[node];
    }

    void dfs(Node* node, unordered_map<Node*, Node*> &cloneOf){

        if(!node)   return;

        // why do we have to stop when a node already exits?
        if(cloneOf.find(node) != cloneOf.end()) return; 

        // fixed memory model bug
        Node* currentClone = new Node(node -> val);
        cloneOf[node] = currentClone;

        for(auto neighbor : node -> neighbors){

            // why aren't we creating a node here and adding it to cloneOf
            dfs(neighbor, cloneOf);
            currentClone -> neighbors.push_back(cloneOf[neighbor]);
        }

    }
};
