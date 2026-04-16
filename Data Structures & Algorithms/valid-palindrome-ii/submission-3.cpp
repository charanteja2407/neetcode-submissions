class Solution {
public:

    bool isPalindrome(string s){

        int i = 0, j = s.size() - 1;
        while(i < j){
            if(tolower(s[i]) != tolower(s[j]))    return false;
            i++; j--;
        }

        return true;
    }
    bool validPalindrome(string s) {
        
        int i = 0, j = s.size() - 1;

        while(i < j){
            if(tolower(s[i]) != tolower(s[j])){
                // string t = s;
                // t.erase(i, 1);
                // if(isPalindrome(t)) return true;
                // t = s;
                // t.erase(j, 1);
                // if(isPalindrome(t)) return true;

                return isPalindrome(s.substr(i+1, j-i)) ||
                isPalindrome(s.substr(i, j-i));
                
            }

            i++; j--;
        }

        return true;
    }
};