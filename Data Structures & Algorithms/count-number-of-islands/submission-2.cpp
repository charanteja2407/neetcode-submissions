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
                    dfs(i, j, rows, cols, grid);
                }
            }
        }

        return noofislands;

    }

private:
    int rows, cols;
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
