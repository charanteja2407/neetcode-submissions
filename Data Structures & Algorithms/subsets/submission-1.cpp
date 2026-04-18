class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> temp;
        recursion(nums, res, 0, temp);

        return res;

    }

private:
    void recursion(vector<int> &nums, vector<vector<int>> &res, 
    int i, vector<int> &temp){

        if(i >= nums.size()) {
            res.push_back(temp);
            return;
        }

        // no pick
        recursion(nums, res, i+1, temp);

        // pick
        temp.push_back(nums[i]);
        recursion(nums, res, i+1, temp);
        temp.pop_back();

    }
};
