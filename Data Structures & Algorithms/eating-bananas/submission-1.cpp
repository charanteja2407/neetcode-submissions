class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxx = 0;
        int n = piles.size();

        for(int i = 0; i < n; i++){
            maxx = max(maxx, piles[i]);
        }

        int l = 1, r = maxx;
        int ans = 0;

        while( l < r){
            int mid = l + (r-l)/2;
            cout << l << ' ' << r << endl;
            
            int res = hoursTaken(piles, mid);
            cout << mid << ' ' << res << endl;
            if(res <= h) r = mid;
            else if(res > h) l = mid + 1;

            cout << l << ' ' << r << ' ' << mid << ' ' << res << endl;
        }

        return l;
    }

private:
    int hoursTaken(vector<int> piles, int k){

        int n = piles.size();
        int totalhours = 0;

        for(int i = 0; i < n; i++){

            totalhours += (piles[i] + k - 1)/ k;
        }

        return totalhours;
    }
};
