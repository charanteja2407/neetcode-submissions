class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        long long val = 1;
        vector<int> prefixprod(nums.size(), 1);
        vector<int> suffixprod(nums.size(), 1);

        for(int i = 0; i < nums.size(); i++)
        {
            val *= nums[i];
            prefixprod[i]= val;
        }
        
        val = 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            val *= nums[i];
            suffixprod[i] = val;
        }
        
        vector<int> res;

        for(int i = 0; i < nums.size(); i++){
            int prep = 1, sufp = 1;
            if( i > 0) prep = prefixprod[i-1];
            if( i < nums.size() - 1) sufp = suffixprod[i+1];
            res.push_back(prep * sufp);
        }
            
        
        return res;

    }
};
