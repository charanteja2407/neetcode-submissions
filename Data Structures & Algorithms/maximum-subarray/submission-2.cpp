class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxans = nums[0];
        for(int i = 0; i < n; i++){
            int sum = nums[i];

            for(int j = i+1; j < n; j++){
                sum += nums[j];
                maxans = max(maxans, sum);
            }
            maxans = max(maxans, sum);
        }

        return maxans;
    }
};
