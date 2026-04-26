class Solution {
public:
    string minWindow(string s, string t) {
        // Base case where the required len of s doesn't matches
        // and when given strings are already equal
        // if either of the strings are empty
        if(t.empty() || s.empty()) return "";
        if (t.size() > s.size()) return "";
        if (s == t) return t;
        
        vector<int> countT(128, 0), countWindow(128, 0);
        for (char c : t) countT[c]++;
        
        int required = 0;
        for(auto i: countT) if(i > 0)   required++;
        int formed = 0;
        int l = 0, minLen = INT_MAX, minStart = 0;
        
        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            countWindow[c]++;
            if (countT[c] > 0 && countWindow[c] == countT[c]) {
                formed++;
            }
            
            while (l <= r && formed == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    minStart = l;
                }
                
                char b = s[l];
                countWindow[b]--;
                if (countT[b] > 0 && countWindow[b] < countT[b]) {
                    formed--;
                }
                l++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};