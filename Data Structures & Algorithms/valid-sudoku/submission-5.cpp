class Solution {
public:

    bool issubboxvalid(int i, int j, vector<vector<char>> &board){

        vector<int> f(9, 0);

        for(int a = i; a < i+3; a++){
            for(int b = j; b < j+3; b++){
                if(board[a][b] != '.')
                    f[board[a][b]-'1']++;

                cout << board[a][b] << ':' << f[board[a][b]-'1'] << ' ';
            }

            cout << endl;
        }

        for(auto i: f) cout << i << ' '; cout << endl;
        for(int i = 0; i < 9; i++){
            if(f[i] > 1)    return false;
        }

        return true;
    }

    bool isrowvalid(int i, int j, vector<vector<char>> &board){

        vector<int> f(9, 0);
        for(int b = j; b < 9; b++){
            if(board[i][b] != '.')
                f[board[i][b]-'1']++;
        }

        for(auto i: f)  if(i > 1)   return false;

        return true;
    }

    bool iscolumnvalid(int i, int j, vector<vector<char>> &board){

        vector<int> f(9, 0);
        for(int a = i; a < 9; a++){
            if(board[a][j] != '.')
            f[board[a][j]-'1']++;
        }

        for(auto i: f)  if(i > 1)   return false;

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        // rows
        for(int i = 0; i < 9; i++){
            if(!isrowvalid(i, 0, board)) return false;
        }

        // cols
        for(int j = 0; j < 9; j++){
            if(!iscolumnvalid(0, j, board)) return false;
        }

        // 3*3 sub boxes
        vector<pair<int, int>> sbi =  // sub box starting indices
        {
            {0, 0}, {0, 3}, {0, 6},
            {3, 0}, {3, 3}, {3, 6},
            {6, 0}, {6, 3}, {6, 6}
        };

        for(int i = 0; i < sbi.size(); i++){

            if(!issubboxvalid(sbi[i].first, sbi[i].second, board))
                return false;
        }

        return true;
    }
};
