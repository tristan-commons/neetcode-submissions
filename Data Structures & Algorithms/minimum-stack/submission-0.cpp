class MinStack {
private:
    stack<int> _mainStack;
    stack<int> _minStack;

public:
    MinStack() {}
    
    void push(int val) {
        _mainStack.push(val);
        int min = INT_MAX;
        if (!_minStack.empty()) {
            min = _minStack.top();
        }

        if (val < min) {
            min = val;
        }

        _minStack.push(min);
    }
    
    void pop() {
        _mainStack.pop();
        _minStack.pop();
    }
    
    int top() {
        return _mainStack.top();
    }
    
    int getMin() {
        return _minStack.top();
    }
};
