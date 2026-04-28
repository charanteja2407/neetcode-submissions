

    class Solution {
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed) {
            
            vector<pair<int, int>> ps;
            int n = position.size();
            // stack<float> s;

            for(int i = 0; i < n; i++){
               ps.push_back({position[i], speed[i]});
            } 

            sort(ps.begin(), ps.end(), greater<pair<int, int>>());
            int noffleets = 0; double last_time = 0;
            for(int i = 0; i < n; i++){
                float tt = (float)(target - ps[i].first ) / (float) ps[i].second;
                cout << tt << ' ';
                // if(!s.empty() && tt <= s.top()) continue;
                // s.push(tt);
                if(last_time < tt){
                    last_time = tt;
                    noffleets++;    
                }
            }

            // return s.size();
            return noffleets;

        }
    };
