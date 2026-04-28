class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int i = 0; int n = nums.size();

        while(i < n){
            int ci = nums[i];

            if(nums[i] == nums[ci])
                return nums[i];
            
            swap(nums[i], nums[ci]);
        }

        return INT_MAX;

    }
};
