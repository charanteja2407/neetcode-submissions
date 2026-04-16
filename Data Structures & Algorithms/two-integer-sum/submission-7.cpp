class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> map;
        int n = nums.size();

        for(int i = 0; i < n; i++){

            if(map.count(target-nums[i]) > 0){
                return {min(map[target - nums[i]], i), max(map[target - nums[i]], i)};
            }
            map[nums[i]] = i;
        }


    }
};
