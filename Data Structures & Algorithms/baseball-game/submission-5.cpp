class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> stack;
        int res = 0;

        for(auto op: operations){

            if(op == "+"){
                int top = stack.top(); stack.pop();
                int newtop = top + stack.top();
                stack.push(top);
                stack.push(newtop);
                res += newtop;
            } else if(op == "D"){
                stack.push(2* stack.top());
                res += stack.top();
            } else if(op == "C"){
                res -= stack.top();
                stack.pop();
            } else {
                
                stack.push(stoi(op));
                res += stack.top();
            }

        }
        
        return res;
    }
};