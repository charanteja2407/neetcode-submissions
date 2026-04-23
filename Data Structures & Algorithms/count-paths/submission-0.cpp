class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << dp[i][j] << endl;
                

                int up = (i > 0)? dp[i-1][j]: 0, 
                left = (j > 0)? dp[i][j-1]: 0;
                
                cout << up << endl;
                
                dp[i][j] = max(1, up + left);
            }
        }

        return dp[m-1][n-1];
    }
};
