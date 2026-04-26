class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f1(26, 0), f2(26, 0);
        int n = s2.size();

        for (auto i : s1) {
            cout << i << ':' << f1[i - 'a'] << "+1" << endl;
            f1[i - 'a']++;
        }

        cout << endl;

        int a = s1.size();

        int i = 0;
        int r = 0;
        while (a--) {
            f2[s2[r] - 'a']++;
            cout << s2[r] << ":" << f2[s2[r] - 'a'] << "+1" << endl;

            r++;
        }
        while (r < n - a) {
            if (f1 == f2) return true;

            cout << s2[r] << ":" << f2[s2[r] - 'a'] << "+1" << endl;
            f2[s2[r] - 'a']++;
            r++;

            cout << s2[i] << ":" << f2[s2[i] - 'a'] << "-1" << endl;
            f2[s2[i] - 'a']--;

            i++;
        }

        return false;
    }
};
