class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string res = "";
        if(mp.find(key) == mp.end())    return res;
        
        auto &v = mp[key];
        if(v.empty())   return res;

        int l = 0, h = v.size() - 1;
        while ( l <= h){
            int mid = l + (h-l)/2;
            if(v[mid].first <= timestamp){
                res = v[mid].second;
                l = mid + 1;
            } else h = mid - 1;
        }

        return res;
    }
};
