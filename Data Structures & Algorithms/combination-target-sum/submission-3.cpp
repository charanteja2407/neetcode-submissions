class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res{};
        vector<int> temp{};
        solver(nums, 0, temp, res, target);
        return res;
    }

    void solver(vector<int> &nums, int i, vector<int> &temp, vector<vector<int>> &res, int target){
        
        if(target == 0){
            res.push_back(temp);
            return;
        }

        if(nums[i] > target || i >= nums.size()) return;

        solver(nums, i+1, temp, res, target); // i+1, as ith element needed to be skipped

        temp.push_back(nums[i]);
        solver(nums, i, temp, res, target - nums[i]); // as same no. can be choosen any number of times.  i is not incremented;
        temp.pop_back();
    }
};
