class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int i = 0, j, k;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        while(i <= nums.size() - 3){
            // int sum = nums[i];
            while(i > 0 && nums[i] == nums[i-1]) i++;
            j = i+1, k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                } 
                else if( sum < 0)    j++;
                else k--;
            }
            i++;
        }

        return res;

    }
};
