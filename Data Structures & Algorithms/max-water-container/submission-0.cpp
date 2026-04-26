class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;
        int maxvol = 0; int beststart = 0, bestend = heights.size() - 1;
        while(i < j){
            int vol = min(heights[i], heights[j]) * (j-i);
            cout << vol << ' ';
            if(vol > maxvol){
                maxvol =  vol;
                beststart = i;
                bestend = j;
            }
            if(heights[i] < heights[j]) i++;
            else if(heights[j] < heights[i]) j--;
            else {i++; j--;}
        }

        return maxvol;
    }
};
