class Solution {
public:
    bool isPalindrome(string s) {
        
        int i = 0, j = s.size() - 1;
        while(i < j){

            if(!isalnum(static_cast<unsigned char> (s[i]))){
                i++;
            }
            if(!isalnum(static_cast<unsigned char> (s[j])))
                j--;

            if(isalnum(static_cast<unsigned char>( s[i])) && isalnum(static_cast<unsigned char> (s[j]))){
                if(tolower(s[i]) != tolower(s[j])){
                    return false;
                }

                i++; j--;
            }
        }

        return true;
    }
};
