class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ind = 0;

        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r-l)/2;
            int curr = nums[mid];

            if(curr >= target){
                r = mid - 1;
            } else {
                l = mid+1;
            }
        }

        return l;
    }
};