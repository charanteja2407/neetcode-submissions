class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int res = recursion(coins, amount, 0, 0);

        return (res != INT_MAX)? res: -1;

    }


    int recursion(vector<int> &coins, int amount, int i, int noc){

        if(amount == 0){
            return noc;
        }

        if(amount <= 0 ||i >= coins.size()){
            return INT_MAX;
        }

        int skip = recursion(coins, amount, i+1, noc);

        int take = recursion(coins, amount - coins[i], i, noc + 1);

        return min(skip, take);
    }
};
