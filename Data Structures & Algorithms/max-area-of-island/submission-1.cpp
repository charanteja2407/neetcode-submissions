class Solution {
public:

    int rows;
    int cols;
    int maxx = 0;
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        rows = grid.size();
        cols = grid[0].size();

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    int c = 0;
                    // dfs(i, j, grid, c);
                    bfs(i, j, grid, c);
                    maxx = max(maxx, c);
                }
            }
        }

        return maxx;

    }

    void bfs(int i, int j, vector<vector<int>> &grid, int &count){

        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;
        // count = 0;

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            count++;
            cout << count << endl;
            
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < 0 || nc < 0 || nr >= rows || nc >= cols)    continue;
                
                if(grid[nr][nc] == 0)   continue;
                
                q.push({nr, nc});
                grid[nr][nc] = 0;
            }
        }

    }

    void dfs(int i, int j, vector<vector<int>> &grid, int &count){

        if(i < 0 || j < 0 || i >= rows || j >= cols)    return;

        if(grid[i][j] == 0)   return;

        grid[i][j] = 0;
        count++;

        dfs(i+1, j, grid, count);
        dfs(i-1, j, grid, count);
        dfs(i, j+1, grid, count);
        dfs(i, j-1, grid, count);

    }
};
