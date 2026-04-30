class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        if(n <= 1)  return n;

        vector<bool> vis(n, 0);
        vector<vector<int>> adj(n);
        int count = 0;

        // 1. Making adj list from edges
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // 2. parsing through each nodes 
            // if not visited do dfs and vis all the connected nodes
            // before doing dfs increment countofcomponents by 1
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                dfs(i, vis, adj);
            }
        }
        // 3. return count of components.
        return count;
    }

private:
    
    void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj){
        vis[u] = true;

        for(auto v: adj[u]){
            if(!vis[v]) // only if not visited
                dfs(v, vis, adj);
        }
    }
};
