class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0];

        return max(rob1(vector<int>(nums.begin() + 1, nums.end())),
        rob1(vector<int>(nums.begin(), nums.end() - 1)));
    }

    int rob1(vector<int> nums){

        int prev2 = 0, prev1 = 0;

        for(int i = 0; i < nums.size(); i++){
            int take = nums[i] + prev2;
            int skip = prev1;

            prev2 = prev1;
            prev1 = max(skip, take);
        }

        return prev1;
    }
};
