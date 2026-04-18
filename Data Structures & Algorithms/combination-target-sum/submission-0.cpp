class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        set<vector<int>> res;
        vector<int> temp;
        solver(nums, 0, temp, res, 0, target);
        return vector<vector<int>> (res.begin(), res.end());
    }

    void solver(vector<int> &nums, int i, vector<int> &temp, set<vector<int>> &res, int sum, int target){
        
        if(sum == target){
            res.insert(temp);
            return;
        }

        if(sum > target || i >= nums.size()) return;

        solver(nums, i+1, temp, res, sum, target);

        temp.push_back(nums[i]);
        solver(nums, i, temp, res, sum + nums[i], target);
        temp.pop_back();
    }
};
