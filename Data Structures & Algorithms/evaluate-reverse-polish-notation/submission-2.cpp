class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int a, b;
        int n = tokens.size();
        stack<int> s;

        for(int i = 0; i < n; i++){
            
            int num = 0;
            if(tokens[i][0] == '-' && tokens[i].size() > 1){
                num = stoi(tokens[i].substr(1, tokens[i].size() - 1));
                s.push(-1*num);
            } else if(isdigit(tokens[i][0])){
                num = stoi(tokens[i]);
                s.push(num);
            } else {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();

                s.push(operate(a, b, tokens[i]));
            }
        }

        return s.top();
    }

private:
    int operate(int a, int b, string op){
        if(op == "+")   return a + b;
         else if(op == "-") return b - a;
         else if(op == "*") return a * b;
         else return floor(b/a);
    }
};
