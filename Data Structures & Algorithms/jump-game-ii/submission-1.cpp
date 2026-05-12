class Solution {
public:
    vector<long long> dp;
    int n;
    int jump(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, INT_MAX);
        return min_jumps(0, nums);
    }

    long long min_jumps(int i, vector<int> &nums){
        if(i >= n - 1)
            return 0;
        
        if(dp[i] == INT_MAX){
            for(int j = i+1; j <= i+nums[i] && j < n; j++){
                dp[i] = min(dp[i], min_jumps(j, nums) + 1);
            }
        }

        cout << i << ' ' << dp[i] << endl;

        return dp[i];
    }
};
