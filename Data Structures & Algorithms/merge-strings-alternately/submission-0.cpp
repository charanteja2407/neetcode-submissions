class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string res = "";

        int a = word1.size(), b = word2.size();
        int i = 0, j = 0;

        while( i < a || j < b){

            if(i < a) res += word1[i];
            if(j < b) res += word2[j];
            i++; j++;
        }

        return res;
    }
};