class Solution {
public:
    int calPoints(vector<string>& operations) {
        // last record is important and maitaining the sum;
        // for + we need last two records and add them.
        // for d last one, add 2*last one to the sum
        // and c , minus the last record from the sum and here we need to keep tract of last three records

        // lets do brute force first i.e. maintaining a vector
        vector<int> bin;

        for(int i = 0; i < operations.size() ; i++){
            // the first char of the string can be digit or '-' negative sign so it's recommended to check second char as well.
            if(isdigit(static_cast<unsigned char>(operations[i][0])) || isdigit(static_cast<unsigned char>(operations[i][1])))
                bin.push_back(stoi(operations[i]));
            else if(operations[i] == "+")
            {
                if(bin.size() < 2) continue;
                bin.push_back(bin[bin.size() - 1] + bin[bin.size() - 2]);
            } else if(operations[i] == "D"){
                bin.push_back(2*bin.back());
            } else if(operations[i] == "C"){
                bin.pop_back();
            }

            for(auto i: bin)    cout  << i << ' '; cout << endl;
        }

        return accumulate(bin.begin(), bin.end(), 0);
    }
};