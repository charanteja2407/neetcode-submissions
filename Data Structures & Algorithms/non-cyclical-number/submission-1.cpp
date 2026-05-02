class Solution {
public:
    bool isHappy(int n) {
       set<int> s;
       while(!s.count(n)){
            int k= 0;
            cout << n << ' ';
            s.insert(n);
            while(n){
                int digit = n%10;
                n /= 10;
                k = k + digit*digit;
            }
            n = k;
            if(n == 1)  return true;
       }

       return false;
    }
};
