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
        
        if(node == nullptr) return nullptr;

        unordered_map<Node*, Node*> cloneOf; // orignal -> clone
        queue<Node*> q;
        q.push(node);

        Node* clone = new Node(node -> val);
        cloneOf[node] = clone;


        while(!q.empty()){
            Node* org = q.front();
            q.pop();

            Node* currentClone = cloneOf[org];

            for(auto neighbor: org -> neighbors){
                
                if(cloneOf.find(neighbor) == cloneOf.end()){
                    Node* neighClone = new Node(neighbor -> val);
                    cloneOf[neighbor] = neighClone;
                    q.push(neighbor);
                }

                currentClone -> neighbors.push_back(cloneOf[neighbor]);
            }
        }

        return cloneOf[node];

    }
};
