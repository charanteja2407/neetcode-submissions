class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minn = INT_MAX;
        int res = 0;

        for(int i = 0; i < prices.size(); i++){
            minn = min(minn, prices[i]);
            res = max(res, prices[i] - minn);
        }

        return res;
    }
};
