class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        bool newint = false;

        for(int i = n-1; i >=0; i--){
            if(digits[i] < 9){
                digits[i] += 1;
                return digits;
            } else {
                digits[i] = 0;
            }

            if(i == 0 && digits[i] == 0){
               newint = true;
            }
        }

        // vector<int> neww;
        // neww.push_back(1);
        if(newint){
            // for(auto i: digits){
            //     neww.push_back(i);
            // }
            // return neww;
            digits.insert(digits.begin(), 1);
        }
        
        return digits;

    }
};
