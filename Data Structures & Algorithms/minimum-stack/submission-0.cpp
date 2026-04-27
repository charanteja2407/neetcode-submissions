class MinStack {
public:
    vector<int> s;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push_back(val);
    }
    
    void pop() {
        if(!s.empty())
            s.pop_back();
    }
    
    int top() {
        if(!s.empty()){
            return s[s.size() - 1];
        }

        return -1;
    }
    
    int getMin() {
        int minn = INT_MAX;
        for(auto i: s){
            minn = min(minn, i);
        }

        return minn;
    }
};
