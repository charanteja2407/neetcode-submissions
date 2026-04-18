class Solution {
public:
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
        
        n = nums.size();
        vector<int> c;
        vector<char> used(n, 0);
        vector<vector<int>> res;
        // takeNotTake(0, nums, used, c, res);
        swapPermute(0, nums, res);

        return res;
    }

    void swapPermute(int start, vector<int>& nums, vector<vector<int>> &res){
        if(start == n){
            res.push_back(nums);
            return;
        }

        for(int i = start; i < n; i++){
            swap(nums[start], nums[i]);
            swapPermute(start+1, nums, res);
            swap(nums[start], nums[i]);
        }
    }

    void takeNotTake(int idx, vector<int> &nums, vector<char> &used, vector<int> &c, vector<vector<int>> &res){
        if(idx == n){
            res.push_back(c);
            return;
        }

        for(int i = 0; i < n; i++){
            if(!used[i]){

                c.push_back(nums[i]);
                used[i] = 1;
                takeNotTake(idx+1, nums, used, c, res);
                c.pop_back();
                used[i] = 0;
            }
        }
    }
};
