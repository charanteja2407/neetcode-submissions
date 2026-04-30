class Solution {
   public:
    // 1. Tree has exactly n-1 edges where n is number of vertices/nodes.
    // 2. Tree is a acyclic graph
    // 3. Every node is connected
    // 4. Exactly one path between any two nodes in tree
    bool validTree(int n, vector<vector<int>>& edges) {
        if(!n)  return true;
        if (edges.size() != n - 1) return false;

        vector<int> visited(n, 0);
        vector<vector<int>> adj(n);

        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // check for cycle
        if(dfs(0, -1, adj, visited))  return false;

        // check connectivity (all nodes are visited)
        for(auto u: visited){
            if(!u)
                return false; // disconnected component -> it's not a tree
        }

        return true;
    }

    bool dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[u] = true;

        for (auto v : adj[u]) {
            if(!vis[v]){
                if(dfs(v, u, adj, vis)) return true;
            }
            else if(v != parent) return true; // back edge -> cycle
        }

        return false;
    }
};
