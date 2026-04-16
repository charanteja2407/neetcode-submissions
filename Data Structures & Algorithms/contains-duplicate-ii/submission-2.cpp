class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        vector<pair<int, int>> d;

        for(int i = 0; i < nums.size(); i++){
            d.push_back({nums[i], i});
        }
        sort(d.begin(), d.end());

        for(int i = 1; i < nums.size(); i++){
            if(d[i].first == d[i-1].first && abs(d[i].second - d[i-1].second <= k))
                return true;
        }

        return false;
    }
};