class Solution {
   public:
    vector<vector<int>> extractededges;
    vector<int> parentof;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parentof.assign(n+1, 0);

        vector<bool> vis(n + 1);
        vector<vector<int>> adj(n + 1);

        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        extractededges.clear();
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                // cout << i << endl;
                if (dfs(i, -1, vis, adj)) {
                    // cout << "found cycle at " << i << endl;
                    break;
                }
            }
        }

        cout << "ex: ";
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < extractededges.size(); j++) {
                cout << extractededges[j][0] << ", " << extractededges[j][1] << endl;
                vector<int> revedg = {extractededges[j][1], extractededges[j][0]};
                if (extractededges[j] == edges[i] ||
                    revedg == edges[i])
                    return edges[i];
            }
        }

        // cout << endl;

        return {};
    }

    bool dfs(int u, int parent, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[u] = true;
        parentof[u] = parent;
        // cout << u << " in dfs" << endl;

        for (auto v : adj[u]) {
            if (!vis[v]) {
                if (dfs(v, u, vis, adj))
                    return true;
            } else if (v != parent) {
                int cur = u;
                while (cur != v) {
                    extractededges.push_back({cur, parentof[cur]});
                    cur = parentof[cur];
                }
                extractededges.push_back({u, v});
                return true;
            }
        }

        return false;
    }
};
