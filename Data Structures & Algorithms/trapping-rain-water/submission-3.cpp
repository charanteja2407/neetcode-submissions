class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size() == 0) return 0;
        int l = 0, r = height.size()-1;
        int maxl = 0, maxr = 0;
        int watervol = 0;
        while(l <= r){
            
            if(maxl <= maxr){
                if(height[l] < maxl){
                    watervol += maxl - height[l];
                }
                else maxl = height[l];
                l++;
            } else {
                if(height[r] < maxr){
                    watervol += maxr - height[r];
                }
                else maxr = height[r];
                r--;
            }

        }
        return watervol;

    }
};
