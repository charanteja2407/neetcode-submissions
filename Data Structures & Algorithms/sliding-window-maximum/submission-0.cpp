class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        priority_queue<pair<int, int>> heap;
        vector<int> res;

        int r = 0;
        for(; r < k; r++){
            heap.push({nums[r], r});
        }
        res.push_back(heap.top().first);

        for(; r < n; r++){

            heap.push({nums[r], r});

            /// removing the lements whose index si outside of the window [r-k+1, r]
            while(heap.top().second < r - k + 1){
                heap.pop();
            }

            res.push_back(heap.top().first);
        }

        return res;
    }
};
