class Solution {
public:
    int mySqrt(int x) {
        

        int l = 1, r = x/2 + 1;

        while(l <= r){
            int m = l + (r-l)/2;
            long long res = (long long) m*m;
            if(res == x) return m;
            else if( res > x) r = m-1;
            else l = m+1;   

            cout << l << ' ' << r << ' ' << m << ' ' << res << endl;
        }

        return r;

    }
};