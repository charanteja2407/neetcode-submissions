class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;

        unordered_map<int, int> lastindex;

        int j = 0;
        lastindex[s[j]] = j;
        int ans = 0;

        for(int i = 1; i < s.size(); i++){
            if(lastindex.count(s[i])){
                j = max(j, lastindex[s[i]]+1);
            }

            lastindex[s[i]] = i;
            ans = max(ans, abs(j - i));
        }

        return ans + 1;
    }


};
