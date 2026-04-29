class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dp(nums, 0, temp, res);

        return vector<vector<int>> (res.begin(), res.end());
    }

    void dp(vector<int> &nums, int i, vector<int> &temp, vector<vector<int>> &res){
        if(i == nums.size()){
            res.push_back(temp);   
            return;
        }
        // no take
        int ni = i+1;
        while(ni < nums.size() && nums[ni] == nums[i])   ni++;
        dp(nums, ni, temp, res);
        // take
        temp.push_back(nums[i]);
        dp(nums, i+1, temp, res);
        temp.pop_back();

    }
};
