class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        vector<int> minv, maxv;
        int minn = INT_MAX, maxx = 0;

        for(int i = 0; i < prices.size(); i++){
            minn = min(minn, prices[i]);
            minv.push_back(minn);
        }

        for(int i = prices.size() - 1; i >= 0; i--){
            maxx = max(maxx, prices[i]);
            maxv.push_back(maxx);
        }

        reverse(maxv.begin(), maxv.end());

        int res = 0;

        for(int i = 0; i < prices.size(); i++){
            res = max(res, maxv[i] - minv[i]);
        }

        return res;


    }
};
