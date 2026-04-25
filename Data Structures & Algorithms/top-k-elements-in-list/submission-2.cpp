class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
        unordered_map<int, int> mp;
        for(int i: nums){
            mp[i]++;
        }

        for(auto i: mp){
            p.push({i.second, i.first});
            if(p.size() > k) p.pop();
        }

        vector<int> res;

        for(int i = 0; i < k; i++){
            res.push_back(p.top().second);
            p.pop();
        }

        return res;
    }
};
