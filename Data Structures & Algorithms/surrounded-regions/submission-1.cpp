class Solution {
public:
    int n, m;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};



    void solve(vector<vector<char>>& board) {
        
        n = board.size(), m = board[0].size();
        if(board.empty() || board[0].empty())   
            return;

        // 1. Marking all O regions that are connected to border (O -> S)
        
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O')
                dfs(board, i, 0);
            
            if(board[i][m-1] == 'O')
                dfs(board, i, m-1);
        }

        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O')
                dfs(board, 0, j);
            
            if(board[n-1][j] == 'O')
                dfs(board, n-1, j);
        }

        // 2. fliping (O -> X) && (S -> O)

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O')  board[i][j] = 'X';
                if(board[i][j] == 'S')  board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>> &board, int i, int j){
    if(i < 0 || j < 0 || i >= n || j >= m || 
    board[i][j] != 'O')
        return;

    board[i][j] = 'S';

    for(int d = 0; d < 4; d++){
        int nr = i + dr[d];
        int nc = j + dc[d];

        dfs(board, nr, nc);
    }
    }
};
