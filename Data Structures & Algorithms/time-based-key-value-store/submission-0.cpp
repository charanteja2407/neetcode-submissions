class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
            mp[key].push_back({value, timestamp});
        
    }
    
    string get(string key, int timestamp) {
        
        if(mp.find(key) != mp.end()){
            if(mp[key].size() > 1){
                auto &searchspace = mp[key];

                int l = 0, h = searchspace.size() - 1;
                while( l <= h){
                    int m = l + (h-l)/2;
                    if(searchspace[m].second <= timestamp) l = m + 1;
                    else h = m - 1;
                }

                return (l == 0)? "": searchspace[l-1].first;

            }
        } else return "";

    }
};
