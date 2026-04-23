class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        queue<tuple<int, int, int>> q; // r, c, dist

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // find all treasures and enqueue in q
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){

                if(grid[i][j] == 0)
                    q.push({i, j, 0});
            }
        }

        while(!q.empty()){

            auto [r, c, d] = q.front(); q.pop();

            for(int i = 0; i < 4; i++){
                
                int nr = r + dr[i], nc = c + dc[i];

                if(nr < 0 || nc < 0 || nr >= rows || nc >= cols)
                    continue;
                

                // if its not water or already visited - skip
                // why if it's already visisted can there be no option where 
                // the earlier dist is larger than the present value
                if(grid[nr][nc] == -1 || grid[nr][nc] != INT_MAX)   
                    continue;
                
                grid[nr][nc] = d + 1;
                q.push({nr, nc, d+1});
            }
        }

    }
};
