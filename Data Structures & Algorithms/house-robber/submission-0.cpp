class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return 0;
        
        int prev1 = 0, prev2 = 0;

        for(int i = 0; i < n; i++){

            int take = nums[i] + prev2;
            int skip = prev1;

            prev2 = prev1;

            prev1 = max(skip, take);
            
        }

        return prev1;
    }
};
