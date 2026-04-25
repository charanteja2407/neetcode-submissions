class Solution {
public:
    // Encode: list -> single string
    string encode(vector<string>& strs) {
        string encoded = "";
        for(const string& str : strs) {
            string len_str = to_string(str.size());  // String first!
            encoded += "_)" + len_str + "_" + str;
        }
        cout << encoded << endl;
        return encoded;
    }
    
    // Decode: single string -> list
    vector<string> decode(string s) {
        vector<string> res;
        for(int i = 0; i < s.size(); ) {
            if(s[i] == '_' && i + 1 < s.size() && s[i + 1] == ')') {  // Freshly typed
                i += 2;
                
                // Parse length digits
                string len_str = "";
                while(i < s.size() && isdigit(s[i])) {
                    len_str += s[i];
                    i++;
                }
                int count = stoi(len_str);

                if(s[i] == '_') i++;
                
                // Extract string
                string ss = "";
                while(count > 0 && i < s.size()) {
                    ss += s[i];
                    i++;
                    count--;
                }
                res.push_back(ss);
            } else {
                i++;
            }
        }
        return res;
    }
};