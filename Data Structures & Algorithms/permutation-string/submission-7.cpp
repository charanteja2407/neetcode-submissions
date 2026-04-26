class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26, 0), f2(26, 0);
        int n = s2.size();
        int a = s1.size();

        int i = 0;
        int r = 0;

        if(a > n) return false;

        for (int i = 0; i < a; i++) {
            // cout << s1[i] << " s1:" << f1[s1[i] - 'a'] << "+1" << endl;
            f1[s1[i] - 'a']++;
            // cout << s2[r] << ":" << f2[s2[r] - 'a'] << "+1" << endl;
            f2[s2[r] - 'a']++;
            r++;
        }

        if(f1 == f2)     return true;

        // cout << endl;

        while (r != n) {
            // cout << s2[i] << ":" << f2[s2[i] - 'a'] << "-1" << endl;
            f2[s2[i] - 'a']--;
            i++;
            // cout << s2[r] << ":" << f2[s2[r] - 'a'] << "+1" << endl;
            f2[s2[r] - 'a']++;
            r++;

            if (f1 == f2) return true;
        }

        return false;
    }
};
