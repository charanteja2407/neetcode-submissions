class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, n = matrix.size(), m = matrix[0].size(), h = m*n - 1;

        while(l <= h){
            int mid = l + (h-l)/2;
            int row = mid/m, col = mid%m;

            int res = matrix[row][col];

            if(res == target) return true;
            else if(res > target) h = mid - 1;
            else l = mid + 1;
        }

        return false;
    }
};
