class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        rows = grid.size();
        cols = grid[0].size();

        int noofislands = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){

                if(grid[i][j] == '1'){
                    noofislands++;
                    // dfs(i, j, rows, cols, grid);
                    bfs(i, j, grid);
                }
            }
        }

        return noofislands;

    }

private:
    int rows, cols;

    vector<int> dr = {-1,  1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    void bfs(int r, int c, vector<vector<char>> &grid){
        
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '0';

        while(!q.empty()){

            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr< 0 || nc < 0 || nr >= rows || nc >= cols)
                    continue;

                if(grid[nr][nc] != '1')
                    continue;
                
                grid[nr][nc] = '0';
                q.push({nr, nc});
            }
        }
    }

    void dfs(int r, int c, int rows, int cols, vector<vector<char>> &grid){

        if( r < 0 || r >= rows || c < 0 || c >= cols)
            return;
        
        if(grid[r][c] != '1'){
            return;
        }
        
        grid[r][c] = '0';


        dfs(r+1, c, rows, cols, grid);
        dfs(r, c+1, rows, cols, grid);
        dfs(r-1, c, rows, cols, grid);
        dfs(r, c-1, rows, cols, grid);
    }
};
