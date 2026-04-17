class Solution {
public:
    bool isValid(string s) {
        
        stack<int> stack;
        int i = 0;

        while(i < s.size()){
            
            if(s[i] == ')' && !stack.empty() && stack.top() == '(')
            {
                stack.pop();
            } else if(s[i] == '}' && !stack.empty() && stack.top() == '{')
            {
                stack.pop();
            }   else if(s[i] == ']' && !stack.empty() && stack.top() == '[')
            {
                stack.pop();
            } else stack.push(s[i]);

            i++;
        } 

        return stack.size() == 0;
    }
};
