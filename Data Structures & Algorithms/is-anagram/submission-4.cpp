class Solution {
public:
    bool isAnagram(string s, string t) {
        
        unordered_map<char, int> fs, ft;

        for(auto i: s) fs[i]++;
        for(auto i: t) ft[i]++;

        return fs == ft;
    }
};
