class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, steps = 0;
        while(r < n -1 ){

            int max_reach = r;

            for(int i = l; i <= r; i++){
                if(nums[i] + i > max_reach)
                    max_reach = nums[i] + i;
            }
            steps++;
            l = r + 1;
            r = max_reach;
        }

        return steps;
    }
};
