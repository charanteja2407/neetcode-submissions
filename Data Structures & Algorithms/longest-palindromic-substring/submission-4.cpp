class Solution {

    private:

    void genrateSubStrings(string s, int i, string subs, vector<string> &res){

        for(int i = 0; i < s.size(); i++){
            for(int j = i+1; j <= s.size(); j++){
                res.push_back(s.substr(i, j-i));
            }
        }
        
    }

    
    bool isPalindrome(string s){

        int l = 0, r = s.size() - 1;

        while(l < r){
            if(s[l] != s[r]) return false;
            l++; r--;
        }

        return true;
    }

public:


    string longestPalindrome(string s) {
        
        vector<string> substrs;

        genrateSubStrings(s, 0, "", substrs);

        sort(substrs.begin(), substrs.end(), [](const string &a, const string &b){
            return a.size() < b.size();
        });

        reverse(substrs.begin(), substrs.end());

        for(auto i: substrs){
            if(isPalindrome(i))
                return i;
        }

        return s.substr(0, 1);
    }
};
