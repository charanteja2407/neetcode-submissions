class Solution {
public:
    int characterReplacement(string s, int k) {
        
        vector<int> al(26, 0);
        int maxfreq = 0, maxlen = 0, l = 0;

        for(int r = 0; r < s.size(); r++){
            al[s[r]-'A']++;
            maxfreq = max(maxfreq, al[s[r]-'A']);
            if(r - l + 1 - maxfreq > k) 
            {
                al[s[l]-'A']--; // update the hashmap;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};
