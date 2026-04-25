class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        // Modifying the existing vector intervals is very expensive.
        // i.e. adding and removing an element from vector is O(N) operation.
        // it's better to create a new vector and return that in the end.

        vector<vector<int>> res;

        int i = 0, n = intervals.size();

        while( i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i++]);
        }

        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        while(i < n){
            res.push_back(intervals[i++]);
        }

        return res;
        
    }
};
