class Solution {
public:

    int rows;
    int cols;
    int maxx = 0;

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        rows = grid.size();
        cols = grid[0].size();
        

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    int c = 0;
                    dfs(i, j, grid, c);
                    maxx = max(maxx, c);
                }
            }
        }

        return maxx;

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
