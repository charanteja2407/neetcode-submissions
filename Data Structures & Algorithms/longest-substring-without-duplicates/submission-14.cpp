class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;

        // vector lookup is faster than ordered_map & set
    // here check is not necessary i.e. lastindex[s[i]] != -1; as we are computing j independent of it
    

        // unordered_map<char, int> lastindex;
        vector<int> lastindex(256, -1);

        int j = 0;
        int ans = 0;

        for(int i = 0; i < s.size(); i++){
            // if(lastindex.count(s[i])){
            // if(lastindex[s[i]] != -1){
                j = max(j, lastindex[s[i]]+1);
            // }

            lastindex[s[i]] = i;
            ans = max(ans, i - j + 1);
        }

        return ans ;
    }


};
