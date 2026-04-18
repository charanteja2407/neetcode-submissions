class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res{};
        vector<int> curr{};

        solver(0, nums, curr, res, target);

        // set<vector<int>> d(res.begin(), res.end());

        // return vector<vector<int>> (d.begin(), d.end());
        return res;
    }

   private:
    void solver(int i, vector<int>& nums, vector<int>& curr, vector<vector<int>>& res,
                int remain) {

        if (remain == 0) {
            res.push_back(curr);
            return;
        }
        if (i >= nums.size() || nums[i] > remain) return;

        curr.push_back(nums[i]);
        solver(i + 1, nums, curr, res, remain - nums[i]);
        curr.pop_back();

        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        solver(i + 1, nums, curr, res, remain);

    }
};
