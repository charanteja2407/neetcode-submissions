class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;
        int n = strs.size();
        vector<vector<string>> res;
        for(int i = 0; i < n; i++){
            vector<int> alpha(26,0);
            for(int j = 0; j < strs[i].size(); j++){
                alpha[strs[i][j]-'a']++;
            }
            string key = "";
            for(auto i: alpha) key += to_string(i) +",";
            mp[key].push_back(strs[i]);
        }

        for(auto i : mp){
            cout << i.first << ": ";
            for(auto a : i.second){
                cout << a << ' ';
            }
            cout << endl;
        }

        for(auto i: mp){
            res.push_back(i.second);
        }

        return res;
    }
};
