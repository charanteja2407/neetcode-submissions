class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax(n, 0), rightmax(n, 0);
        leftmax[0] = height[0];
        for(int i = 1; i < n; i++ ){
            leftmax[i] = max(leftmax[i-1], height[i]);
            cout << leftmax[i] << ' ';
        }
        cout << endl;
        rightmax[n-1] = height[n-1];
        for(int i = n - 2 ; i >= 0; i--){
            rightmax[i] = max(rightmax[i+1], height[i]);
            cout << rightmax[i] << ' ';
        }
        cout << endl;

        int watervol = 0;
        for(int i = 0; i < n; i++){
            int minh = min(leftmax[i], rightmax[i]);
            cout << minh - height[i] << ' '; 
            watervol +=  (minh - height[i] > 0)? minh - height[i]: 0;
        }

        return watervol;

    }
};
