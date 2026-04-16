class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int, int>> arr;
        int n = nums.size();
        int i = 0, j = nums.size() - 1;

        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }
        
        sort(arr.begin(), arr.end());
        while (i < j){
            if(arr[i].first + arr[j].first == target)
                return {min(arr[i].second, arr[j].second), max(arr[i].second, arr[j].second)};
            else if(arr[i].first + arr[j].first < target)
                i++;
            else j--;
        }

        return {};
    }
};
