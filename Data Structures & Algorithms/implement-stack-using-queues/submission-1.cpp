class MyStack {
public:

    // int size;  reducdant as size of q1 is the size of stack
    // using single queue;

    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
        int i = q.size()-1;
        while(i > 0){
            q.push(q.front());
            q.pop();
            i--;
        }
    }
    
    int pop() {

        int top = q.front(); 
        q.pop();

        return top;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }

    private: queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */