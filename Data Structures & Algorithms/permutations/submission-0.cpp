class Solution {
public:
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
        
        n = nums.size();
        vector<int> c;
        vector<char> used(n, 0);
        vector<vector<int>> res;
        solver(0, nums, used, c, res);

        return res;
    }

    void solver(int idx, vector<int> &nums, vector<char> &used, vector<int> &c, vector<vector<int>> &res){
        if(idx == n){
            res.push_back(c);
            return;
        }

        for(int i = 0; i < n; i++){
            if(!used[i]){

                c.push_back(nums[i]);
                used[i] = 1;
                solver(idx+1, nums, used, c, res);
                c.pop_back();
                used[i] = 0;
            }
        }
    }
};
