class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        if(grid.size() == 1 && grid[0].size() == 1){
            if(grid[0][0] == 1) return -1;
            else return 0;
        }

        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        int freshc = 0, rottenc = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2)
                {
                    rottenc++;
                    q.push({i, j});
                } else if(grid[i][j] == 1){
                    freshc++;
                }
            }
        }

        // if(rottenc == 0)    return 0;
        if(freshc == 0)    return 0;
        vector<int> hd = {0, -1, 0, 1};
        vector<int> vd = {-1, 0, 1, 0};
        int l = 1;

        while(!q.empty()){
            
            queue<pair<int, int>> nq;
            while(!q.empty()){
                auto [a, b] = q.front();
                q.pop();
                // cout << "rt " << a << ' ' << b << endl; 
                for(int i = 0; i < 4; i++){
                    int nr = a + hd[i];
                    int nc = b + vd[i];
                    
                    // cout << "idx: " << nr << ' ' << nc << endl; 

                    if(nr < n && nr >= 0 && nc < m && nc >= 0)
                    if(grid[nr][nc] == 1){
                        // cout << "f - rt " << nr << ' ' << nc << endl; 

                        freshc--;
                        grid[nr][nc] = 2;
                        nq.push({nr, nc});
                    }

                    if(freshc == 0) return l;
                }
            }
            l++;
            q = nq;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return 0;
    }
};
