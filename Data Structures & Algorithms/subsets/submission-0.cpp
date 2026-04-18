class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        int i = 0;
        vector<int> temp;
        recursion(nums, res, i, temp);

        return res;

    }

private:
    void recursion(vector<int> &nums, vector<vector<int>> &res, 
    int i, vector<int> &temp){

        if(i == nums.size()) {
            res.push_back(temp);
            return;
        }

        // pick
        temp.push_back(nums[i]);
        recursion(nums, res, i+1, temp);
        temp.pop_back();
        
        // no pick
        recursion(nums, res, i+1, temp);

    }
};
